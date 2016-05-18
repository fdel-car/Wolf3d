/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:38:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/18 17:53:14 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_glob *gl)
{
	gl->s_x = 600;
	gl->s_y = 400;
	gl->fov = 60;
	gl->posx = 300;
	gl->posy = 300;
	gl->pov = 45;
	gl->sray = 60 / (double)gl->s_x;
	gl->dpp = (gl->s_x / 2) / tan(30 * M_PI / 180);
}

void	ft_detect_wall(t_glob *gl)
{
	int x;

	x = 0;
	gl->ang = gl->pov - 30;
	while (x < gl->s_x)
	{
		if (gl->ang >= 360.0)
			gl->ang -= 360.0;
		gl->h_x = -1;
		gl->h_y = -1;
		gl->v_x = -1;
		gl->v_y = -1;
		if (gl->ang != 0.0 && gl->ang != 180.0)
		{
			gl->h_y = (gl->ang > 0.0 && gl->ang < 180.0) ?
			(int)(gl->posy / 64) * 64 - 1 : (int)(gl->posy / 64) * 64 + 64;
			gl->h_x = gl->posx + (gl->posy - gl->h_y) /
			tan(gl->ang * (double)M_PI / 180);
			gl->ya = (gl->ang > 0.0 && gl->ang < 180.0) ? -64 : 64;
			gl->xa = 64 / tan(gl->ang * (double)M_PI / 180);
			gl->xa = gl->ang > 180.0 ? -gl->xa : gl->xa;
			while (gl->h_x >= 0 && gl->h_x <= 576 && gl->h_y >= 0 && gl->h_y
			<= 576 && gl->map[(int)(gl->h_x / 64)][(int)(gl->h_y / 64)] != 1)
			{
				gl->h_x += gl->xa;
				gl->h_y += gl->ya;
			}
			if (gl->h_x < 0 || gl->h_x > 576 || gl->h_y < 0 || gl->h_y > 576)
			{
				gl->h_x = -1;
				gl->h_y = -1;
			}
		}
		if (gl->ang != 90.0 && gl->ang != 270.0)
		{
			gl->v_x = (gl->ang > 90.0 && gl->ang < 270.0) ?
			(int)(gl->posx / 64) * 64 - 1 : (int)(gl->posx / 64) * 64 + 64;
			gl->v_y = gl->posy + (gl->posy - gl->v_x) *
			tan(gl->ang * (double)M_PI / 180);
			gl->xa = (gl->ang > 90.0 && gl->ang < 270.0) ? -64 : 64;
			gl->ya = 64 * tan(gl->ang * (double)M_PI / 180);
			gl->ya = (gl->ang > 90.0 && gl->ang < 270.0) ? gl->ya : -gl->ya;
			while (gl->v_x >= 0 && gl->v_x <= 576 && gl->v_y >= 0 && gl->v_y
			<= 576 && gl->map[(int)(gl->v_x / 64)][(int)(gl->v_y / 64)] != 1)
			{
				gl->v_x += gl->xa;
				gl->v_y += gl->ya;
			}
			if (gl->v_x < 0 || gl->v_x > 576 || gl->v_y < 0 || gl->v_y > 576)
			{
				gl->v_x = -1;
				gl->v_y = -1;
			}
		}
		gl->d_h = fabs((gl->posx - gl->h_x) / cos(gl->ang * (double)M_PI / 180));
		gl->d_v = fabs((gl->posx - gl->v_x) / cos(gl->ang * (double)M_PI / 180));
		gl->dist = (gl->d_h >= gl->d_v) ? gl->d_v : gl->d_h;
		gl->beta = gl->ang - gl->pov;
		gl->dist = gl->dist * cos(gl->beta * (double)M_PI / 180);
		gl->he_w = (64 / gl->dist) * gl->dpp;
		ft_verline(x, gl);
		gl->ang += gl->sray;
		x++;
	}
	mlx_put_image_to_window(gl->mlx, gl->win, gl->img, 0, 0);
	mlx_destroy_image(gl->mlx, gl->img);
}

void	ft_wolf3d(t_glob *gl)
{
	gl->mlx = mlx_init();
	gl->win = mlx_new_window(gl->mlx, gl->s_x, gl->s_y, "Wolf 3D");
	gl->img = mlx_new_image(gl->mlx, gl->s_x, gl->s_y);
	gl->disp = mlx_get_data_addr(gl->img, &(gl->bpp), &(gl->sizeline),
	&(gl->endian));
	ft_detect_wall(gl);
	mlx_hook(gl->win, 2, 1, ft_key, gl);
	mlx_loop(gl->mlx);
}

int		**ft_map(void)
{
	int i;
	int j;
	int	**map;

	i = 0;
	map = (int **)malloc(sizeof(int *) * 10);
	while (i < 10)
	{
		map[i] = (int *)malloc(sizeof(int) * 10);
		j = 0;
		while (j < 10)
		{
			if (i == 1 || i == 8 || j == 1 || j == 8)
				map[i][j++] = 1;
			else
				map[i][j++] = 0;
		}
		i++;
	}
	return (map);
}

int		main(void)
{
	t_glob	*gl;

	gl = (t_glob *)malloc(sizeof(t_glob));
	gl->map = ft_map();
	ft_init(gl);
	ft_wolf3d(gl);
	return (0);
}
