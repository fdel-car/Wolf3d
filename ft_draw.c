/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 19:47:36 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/16 22:02:47 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_setpixel(t_glob *gl, int x, int y, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				i;

	if (x > gl->s_x || y > gl->s_y || x < 0 || y < 0)
		return ;
	i = y * gl->sizeline + x * gl->bpp / 8;
	r = (color & 0xFF);
	g = ((color & 0xFF00) >> 8);
	b = ((color & 0xFF0000) >> 16);
	gl->disp[i] = r;
	gl->disp[i + 1] = g;
	gl->disp[i + 2] = b;
}

void	ft_verline(int x, t_glob *gl)
{
	int y;

	gl->drawe = (gl->s_y / 2) + (gl->he_w / 2);
	gl->draws = (gl->s_y / 2) - (gl->he_w / 2);
	gl->color = 0xFF00FF;
	y = gl->draws;
	while (y <= gl->drawe)
	{
		ft_setpixel(gl, x, y, gl->color);
		y++;
	}
}
