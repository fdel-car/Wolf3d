/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 19:13:47 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 17:25:00 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_raycast(t_glob *gl)
{
	gl->rayposx = gl->posx;
	gl->rayposy = gl->posy;
	gl->raydirx = gl->dirx + gl->planex * gl->camx;
	gl->raydiry = gl->diry + gl->planey * gl->camx;
	gl->mapx = (int)(gl->rayposx);
	gl->mapy = (int)(gl->rayposy);
	gl->ddistx = sqrt(1 + (gl->raydiry * gl->raydiry) /
			(gl->raydirx * gl->raydirx));
	gl->ddisty = sqrt(1 + (gl->raydirx * gl->raydirx) /
			(gl->raydiry * gl->raydiry));
	gl->hit = 0;
}

void	ft_rayhandle(t_glob *gl)
{
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
}

void	dda(t_glob *gl)
{
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
}

void	handle_tex(t_glob *gl)
{
	if (gl->map[gl->mapx][gl->mapy] == 4)
	{
		gl->tex_x = (int)(gl->wallx * (double)(gl->texw_me));
		if (gl->side == 0 && gl->raydirx > 0)
			gl->tex_x = gl->texw_me - gl->tex_x - 1;
		if (gl->side == 1 && gl->raydiry < 0)
			gl->tex_x = gl->texw_me - gl->tex_x - 1;
	}
	else
	{
		gl->tex_x = (int)(gl->wallx * (double)(gl->texw));
		if (gl->side == 0 && gl->raydirx > 0)
			gl->tex_x = gl->texw - gl->tex_x - 1;
		if (gl->side == 1 && gl->raydiry < 0)
			gl->tex_x = gl->texw - gl->tex_x - 1;
	}
}

void	handle_wall(t_glob *gl)
{
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
	if (gl->side == 0)
		gl->wallx = gl->rayposy + gl->pwd * gl->raydiry;
	else
		gl->wallx = gl->rayposx + gl->pwd * gl->raydirx;
	gl->wallx -= (int)gl->wallx;
	handle_tex(gl);
}
