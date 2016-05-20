/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:38:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/20 20:58:43 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	ft_init(t_glob *gl)
{
	ft_map(gl);
	gl->s_x = 1280;
	gl->s_y = 720;
	gl->posx = 9;
	gl->posy = 5;
	gl->dirx = -1;
	gl->diry = 0;
	gl->planex = 0;
	gl->planey = 0.66;
	gl->oldtime = 0;
	gl->time = 0;
	gl->move_right = 0;
	gl->move_left = 0;
	gl->move_front = 0;
	gl->move_back = 0;
	gl->rot_left = 0;
	gl->rot_right = 0;
	gl->sprint = 0;
}

void	ft_detect_wall(t_glob *gl)
{
	int x;

	x = 0;
	while (x < gl->s_x)
	{
		gl->camx = 2 * x / (double)gl->s_x - 1;
		gl->rayposx = gl->posx;
		gl->rayposy = gl->posy;
		gl->raydirx = gl->dirx + gl->planex * gl->camx;
		gl->raydiry = gl->diry + gl->planey * gl->camx;
		gl->mapx = (int)(gl->rayposx);
		gl->mapy = (int)(gl->rayposy);
		gl->ddistx = sqrt(1 + (gl->raydiry * gl->raydiry) / (gl->raydirx * gl->raydirx));
		gl->ddisty = sqrt(1 + (gl->raydirx * gl->raydirx) / (gl->raydiry * gl->raydiry));
		gl->hit = 0;
		if (gl->raydirx < 0)
		{
			gl->stepx = -1;
			gl->sdistx = (gl->rayposx - gl->mapx) * gl->ddistx;
		}
		else
		{
			gl->stepx = 1;
			gl->sdistx = (gl->mapx + 1.0 - gl->rayposx) * gl->ddistx;
		}
		if (gl->raydiry < 0)
		{
			gl->stepy = -1;
			gl->sdisty = (gl->rayposy - gl->mapy) * gl->ddisty;
		}
		else
		{
			gl->stepy = 1;
			gl->sdisty = (gl->mapy + 1.0 - gl->rayposy) * gl->ddisty;
		}
		while (gl->hit == 0)
		{
			if (gl->sdistx < gl->sdisty)
			{
				gl->sdistx += gl->ddistx;
				gl->mapx += gl->stepx;
				gl->side = 0;
			}
			else
			{
				gl->sdisty += gl->ddisty;
				gl->mapy += gl->stepy;
				gl->side = 1;
			}
			if (gl->map[gl->mapx][gl->mapy] > 0)
				gl->hit = 1;
		}
		if (gl->side == 0)
			gl->pwd = (gl->mapx - gl->rayposx + (1 - gl->stepx) / 2) / gl->raydirx;
		else
			gl->pwd = (gl->mapy - gl->rayposy + (1 - gl->stepy) / 2) / gl->raydiry;
		gl->lineh = (int)((gl->s_y / gl->pwd) * 1.50);
		gl->draws = -gl->lineh / 2 + gl->s_y / 2;
		if (gl->draws < 0)
			gl->draws = 0;
		gl->drawe = gl->lineh / 2 + gl->s_y / 2;
		if (gl->drawe >= gl->s_y)
			gl->drawe = gl->s_y - 1;
		ft_color(gl);
		ft_verline(x, gl);
		x++;
	}
	gl->oldtime = gl->time;
	gl->time = clock();
	gl->ftime = (gl->time - gl->oldtime) / CLOCKS_PER_SEC;
	gl->ms = gl->ftime * 5.0;
	gl->rs = gl->ftime * 3.0;
	mlx_put_image_to_window(gl->mlx, gl->win, gl->img, 0, 0);
	mlx_destroy_image(gl->mlx, gl->img);
	mlx_string_put(gl->mlx, gl->win, 20, 20, 0xFFFFFF, "FPS : ");
	mlx_string_put(gl->mlx, gl->win, 80, 20, 0xFFFFFF, ft_itoa(1.0 / gl->ftime));
}

int		ft_wolf3d(t_glob *gl)
{
	gl->img = mlx_new_image(gl->mlx, gl->s_x, gl->s_y);
	gl->disp = mlx_get_data_addr(gl->img, &(gl->bpp), &(gl->sizeline),
			&(gl->endian));
	ft_move_rot(gl);
	ft_detect_wall(gl);
	if (gl->sprint)
	gl->ms = gl->ms * 2;
	return (0);
}

int		ft_close(t_glob *gl)
{
	int i;

	i = 0;
	while (i < gl->size_mapy)
		free(gl->map[i++]);
	free(gl->map);
	free(gl);
	exit(0);
}

int		main(void)
{
	t_glob	*gl;

	gl = (t_glob *)malloc(sizeof(t_glob));
	ft_init(gl);
	gl->mlx = mlx_init();
	gl->win = mlx_new_window(gl->mlx, gl->s_x, gl->s_y, "Wolf 3D");
	ft_wolf3d(gl);
	mlx_loop_hook(gl->mlx, ft_wolf3d, gl);
	mlx_hook(gl->win, 2, (1L<<0), ft_key_press, gl);
	mlx_hook(gl->win, 3, (1L<<1), ft_key_release, gl);
	mlx_hook(gl->win, 17, 0, ft_close, gl);
	mlx_loop(gl->mlx);
	return (0);
}
