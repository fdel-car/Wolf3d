/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 16:19:55 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/20 20:11:50 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move_rot(t_glob *gl)
{
	if (gl->move_front == 1)
	{
		if (gl->map[(int)(gl->posx + gl->dirx * gl->ms)][(int)(gl->posy)] == 0)
			gl->posx += gl->dirx * gl->ms;
		if (gl->map[(int)(gl->posx)][(int)(gl->posy + gl->diry * gl->ms)] == 0)
			gl->posy += gl->diry * gl->ms;
	}
	if (gl->move_left == 1)
	{
		if (gl->map[(int)(gl->posx - gl->diry * gl->ms)][(int)(gl->posy)] == 0)
			gl->posx -= gl->diry * gl->ms;
		if (gl->map[(int)(gl->posx)][(int)(gl->posy + gl->dirx * gl->ms)] == 0)
			gl->posy += gl->dirx * gl->ms;
	}
	if (gl->move_right == 1)
	{
		if (gl->map[(int)(gl->posx + gl->diry * gl->ms)][(int)(gl->posy)] == 0)
			gl->posx += gl->diry * gl->ms;
		if (gl->map[(int)(gl->posx)][(int)(gl->posy - gl->dirx * gl->ms)] == 0)
			gl->posy -= gl->dirx * gl->ms;
	}
	if (gl->move_back == 1)
	{
		if (gl->map[(int)(gl->posx - gl->dirx * gl->ms)][(int)(gl->posy)] == 0)
			gl->posx -= gl->dirx * gl->ms;
		if (gl->map[(int)(gl->posx)][(int)(gl->posy - gl->diry * gl->ms)] == 0)
			gl->posy -= gl->diry * gl->ms;
	}
	if (gl->rot_right == 1)
	{
		gl->olddirx = gl->dirx;
		gl->dirx = gl->dirx * cos(-gl->rs) - gl->diry * sin(-gl->rs);
		gl->diry = gl->olddirx * sin(-gl->rs) + gl->diry * cos(-gl->rs);
		gl->oldplanex = gl->planex;
		gl->planex = gl->planex * cos(-gl->rs) - gl->planey * sin(-gl->rs);
		gl->planey = gl->oldplanex * sin(-gl->rs) + gl->planey * cos(-gl->rs);
	}
	if (gl->rot_left == 1)
	{
		gl->olddirx = gl->dirx;
		gl->dirx = gl->dirx * cos(gl->rs) - gl->diry * sin(gl->rs);
		gl->diry = gl->olddirx * sin(gl->rs) + gl->diry * cos(gl->rs);
		gl->oldplanex = gl->planex;
		gl->planex = gl->planex * cos(gl->rs) - gl->planey * sin(gl->rs);
		gl->planey = gl->oldplanex * sin(gl->rs) + gl->planey * cos(gl->rs);
	}
}
