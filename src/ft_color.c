/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:31:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 17:22:00 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	loop_tex64_64(t_bitmap *bmp, t_glob *gl, FILE *img, int *tex)
{
	int	buff[1];

	while (bmp->iter++ < gl->texh)
	{
		bmp->iter2 = 0;
		while (bmp->iter2++ < gl->texw)
		{
			fread(buff, 3, 1, img);
			tex[bmp->iter3--] = buff[0];
		}
	}
}

void	texture_grey(t_glob *gl, t_bitmap *bmp)
{
	unsigned char	header[54];
	FILE			*img;

	bmp->iter = 0;
	img = fopen("bmp/greystone.bmp", "r");
	fread(header, sizeof(unsigned char), 54, img);
	fseek(img, header[10], SEEK_SET);
	gl->texw = header[18];
	gl->texh = header[22];
	gl->tex_grey = (int *)malloc(sizeof(int) * (gl->texw * gl->texh + 1));
	bmp->iter3 = gl->texw * gl->texh;
	gl->tex_grey[bmp->iter3--] = 0;
	loop_tex64_64(bmp, gl, img, gl->tex_grey);
}

void	texture_wood(t_glob *gl, t_bitmap *bmp)
{
	unsigned char	header[54];
	FILE			*img;

	bmp->iter = 0;
	img = fopen("bmp/wood.bmp", "r");
	fread(header, sizeof(unsigned char), 54, img);
	fseek(img, header[10], SEEK_SET);
	gl->texw = header[18];
	gl->texh = header[22];
	gl->tex_wood = (int *)malloc(sizeof(int) * (gl->texw * gl->texh + 1));
	bmp->iter3 = gl->texw * gl->texh;
	gl->tex_wood[bmp->iter3--] = 0;
	loop_tex64_64(bmp, gl, img, gl->tex_wood);
}

void	ft_color2(t_glob *gl)
{
	if (gl->side == 0)
	{
		if (gl->stepx < 0)
			gl->color = 0x009900;
		else
			gl->color = 0x00FF00;
	}
	else
	{
		if (gl->stepy < 0)
			gl->color = 0x990000;
		else
			gl->color = 0xFF0000;
	}
}

void	ft_color(t_glob *gl)
{
	int	tex;

	tex = gl->texw * gl->tex_y + gl->tex_x;
	if (gl->map[gl->mapx][gl->mapy] == 2)
		gl->color = gl->tex_wood[tex];
	else if (gl->map[gl->mapx][gl->mapy] == 1)
		gl->color = gl->tex_grey[tex];
	else if (gl->map[gl->mapx][gl->mapy] == 4)
	{
		tex = gl->texw_me * gl->tex_y + gl->tex_x;
		if (tex <= 0)
			tex = 0;
		if (tex >= 48000)
			tex = 47999;
		gl->color = gl->tex_moi[tex];
	}
	else
		ft_color2(gl);
}
