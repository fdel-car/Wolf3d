/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:38:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/20 00:19:49 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_glob *gl)
{
	ft_map(gl);
	gl->s_x = 600;
	gl->s_y = 400;
	gl->posx = 12;
	gl->posy = 12;
	gl->dirx = -1;
	gl->diry = 0;
	gl->planex = 0;
	gl->planey = 0.66;
	gl->oldtime = 0;
	gl->time = 0;
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
		gl->lineh = (int)(gl->s_y / gl->pwd);
		gl->draws = -gl->lineh / 2 + gl->s_y / 2;
		if (gl->draws < 0)
			gl->draws = 0;
		gl->drawe = gl->lineh / 2 + gl->s_y / 2;
		if (gl->drawe >= gl->s_y)
			gl->drawe = gl->s_y - 1;
		gl->color = 0xFF0000;
		ft_verline(x, gl);
		x++;
	}
	mlx_put_image_to_window(gl->mlx, gl->win, gl->img, 0, 0);
	mlx_destroy_image(gl->mlx, gl->img);
}

void	ft_wolf3d(t_glob *gl)
{
	ft_detect_wall(gl);
}

int		main(void)
{
	t_glob	*gl;

	gl = (t_glob *)malloc(sizeof(t_glob));
	ft_init(gl);
	gl->mlx = mlx_init();
	gl->win = mlx_new_window(gl->mlx, gl->s_x, gl->s_y, "Wolf 3D");
	gl->img = mlx_new_image(gl->mlx, gl->s_x, gl->s_y);
	gl->disp = mlx_get_data_addr(gl->img, &(gl->bpp), &(gl->sizeline),
			&(gl->endian));
	ft_wolf3d(gl);
	//mlx_hook(gl->win, 2, (1L<<0), ft_key_press, gl);
	//mlx_hook(gl->win, 3, (1L<<1), ft_key_release, gl);
	mlx_loop(gl->mlx);
	return (0);
}
