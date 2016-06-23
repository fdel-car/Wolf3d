/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 19:47:36 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 17:30:46 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	loop_tex_me(t_bitmap *bmp, t_glob *gl, FILE *img, int *tex)
{
	int	buff[1];
	int	i;

	i = 0;
	while (bmp->iter++ < gl->texh_me)
	{
		bmp->iter2 = 0;
		while (bmp->iter2++ < gl->texw_me)
		{
			fread(buff, 3, 1, img);
			tex[bmp->iter3--] = buff[0];
		}
	}
}

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
	int d;

	y = -1;
	while (++y < gl->draws)
	{
		gl->color = gl->tex_sky[y * 1280 + x];
		ft_setpixel(gl, x, y, gl->color);
	}
	while (y <= gl->drawe)
	{
		d = y * 256 - gl->s_y * 128 + gl->lineh * 128;
		if (gl->map[gl->mapx][gl->mapy] == 4)
			gl->tex_y = (d * gl->texh_me / gl->lineh) / 256;
		else
			gl->tex_y = (d * gl->texh / gl->lineh) / 256;
		ft_color(gl);
		ft_setpixel(gl, x, y, gl->color);
		y++;
	}
	while (y < gl->s_y)
	{
		ft_setpixel(gl, x, y, 0x8F8F8F);
		y++;
	}
}
