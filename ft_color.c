/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:31:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/24 21:14:52 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	texture_grey(t_glob *gl, t_bitmap *bmp)
{
	unsigned char	header[54];
	unsigned char	buff[3 + 1];
	FILE			*img;

	bmp->iter = 0;
	img = fopen("bmp/greystone.bmp", "r");
	fread(header, sizeof(unsigned char), 54, img);
	fseek(img, header[10], SEEK_SET);
	gl->texw = header[18];
	gl->texh = header[22];
	gl->tex_grey = (int *)malloc(sizeof(int) * (gl->texw * gl->texh + 1));
	bmp->iter3 = gl->texw * gl->texh;
	bmp->padding = 0;
	while (((gl->texw * 3 + bmp->padding) % 4) != 0)
		bmp->padding++;
	gl->tex_grey[bmp->iter3--] = 0;
	while (bmp->iter++ < gl->texh)
	{
		bmp->iter2 = 0;
		while (bmp->iter2++ < gl->texh)
		{
			fread(buff, sizeof(unsigned char), 3, img);
			buff[3] = 0;
			bmp->temp = ft_itoa_base(buff[2], 16);
			bmp->temp2 = ft_itoa_base(buff[1], 16);
			bmp->temp2 = ft_strcat(bmp->temp, bmp->temp2);
			bmp->temp3 = ft_itoa_base(buff[0], 16);
			bmp->temp3 = ft_strcat(bmp->temp2, bmp->temp3);
			bmp->nbr = ft_atoi_base(bmp->temp3, 16);
			gl->tex_grey[bmp->iter3--] = bmp->nbr;
		}
	}
}

void	texture_wood(t_glob *gl, t_bitmap *bmp)
{
	unsigned char	header[54];
	unsigned char	buff[3 + 1];
	FILE			*img;

	bmp->iter = 0;
	img = fopen("bmp/wood.bmp", "r");
	fread(header, sizeof(unsigned char), 54, img);
	fseek(img, header[10], SEEK_SET);
	gl->texw = header[18];
	gl->texh = header[22];
	gl->tex_wood = (int *)malloc(sizeof(int) * (gl->texw * gl->texh + 1));
	bmp->iter3 = gl->texw * gl->texh;
	bmp->padding = 0;
	while (((gl->texw * 3 + bmp->padding) % 4) != 0)
		bmp->padding++;
	gl->tex_wood[bmp->iter3--] = 0;
	while (bmp->iter++ < gl->texh)
	{
		bmp->iter2 = 0;
		while (bmp->iter2++ < gl->texh)
		{
			fread(buff, sizeof(unsigned char), 3, img);
			buff[3] = 0;
			bmp->temp = ft_itoa_base(buff[2], 16);
			bmp->temp2 = ft_itoa_base(buff[1], 16);
			bmp->temp2 = ft_strcat(bmp->temp, bmp->temp2);
			bmp->temp3 = ft_itoa_base(buff[0], 16);
			bmp->temp3 = ft_strcat(bmp->temp2, bmp->temp3);
			bmp->nbr = ft_atoi_base(bmp->temp3, 16);
			gl->tex_wood[bmp->iter3--] = bmp->nbr;
		}
	}
}

void	ft_color(t_glob *gl)
{
	int	tex;

	tex = gl->texw * gl->tex_y + gl->tex_x;
	if (gl->map[gl->mapx][gl->mapy] == 3)
		gl->color = gl->tex_wood[tex];
	else
		gl->color = gl->tex_grey[tex];
	/*if (gl->side == 0)
	  {
	  if (gl->stepx < 0)
	  gl->color = tex[(int)gl->tex_x];
	  else
	  gl->color = tex[(int)gl->tex_x];
	  }
	  else
	  {
	  if (gl->stepy < 0)
	  gl->color = tex[(int)gl->tex_x];
	  else
	  gl->color = tex[(int)gl->tex_x];
	  }*/
}
