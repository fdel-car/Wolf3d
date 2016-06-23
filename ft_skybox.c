/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:45:12 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 17:27:12 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_unload(t_glob *gl, char *str)
{
	gl->temp = 0;
	if (str[gl->iter] >= '1' && str[gl->iter] <= '9')
	{
		gl->temp3 = gl->mini_x;
		gl->temp4 = gl->mini_y;
		while (gl->temp < 5)
		{
			gl->mini_x = gl->temp3;
			gl->temp2 = 0;
			while (gl->temp2 < 5)
			{
				ft_setpixel2(gl, gl->mini_x, gl->mini_y, 0xFFFFFF);
				gl->temp2++;
				gl->mini_x++;
			}
			gl->temp++;
			gl->mini_y++;
		}
		gl->mini_y = gl->temp4;
	}
}

void	ft_unload2(t_glob *gl, char *str)
{
	if (str[gl->iter] == '0')
	{
		gl->temp3 = gl->mini_x;
		gl->temp4 = gl->mini_y;
		while (gl->temp < 5)
		{
			gl->mini_x = gl->temp3;
			gl->temp2 = 0;
			while (gl->temp2 < 5)
			{
				ft_setpixel2(gl, gl->mini_x, gl->mini_y, 0x00000);
				gl->temp2++;
				gl->mini_x++;
			}
			gl->temp++;
			gl->mini_y++;
		}
		gl->mini_y = gl->temp4;
	}
	gl->iter++;
}

void	loop_tex1280(t_bitmap *bmp, t_glob *gl, FILE *img, int *tex)
{
	int	buff[1];
	int	i;

	i = 0;
	while (bmp->iter++ < gl->texh_s)
	{
		bmp->iter2 = 0;
		while (bmp->iter2++ < gl->texw_s)
		{
			fread(buff, 3, 1, img);
			tex[bmp->iter3--] = buff[0];
		}
	}
}

void	ft_skybox(t_glob *gl, t_bitmap *bmp)
{
	int		size[2];
	FILE	*img;

	bmp->iter = 0;
	img = fopen("bmp/skybox.bmp", "r");
	fseek(img, 18, SEEK_SET);
	fread(size, sizeof(int), 2, img);
	gl->texw_s = size[0];
	gl->texh_s = size[1];
	fseek(img, 122, SEEK_SET);
	gl->tex_sky = (int *)malloc(sizeof(int) * (gl->texw_s * gl->texh_s + 1));
	bmp->iter3 = gl->texw_s * gl->texh_s;
	gl->tex_sky[bmp->iter3--] = 0;
	loop_tex1280(bmp, gl, img, gl->tex_sky);
}

void	texture_me(t_glob *gl, t_bitmap *bmp)
{
	int		size[2];
	FILE	*img;

	bmp->iter = 0;
	img = fopen("bmp/moi.bmp", "r");
	fseek(img, 18, SEEK_SET);
	fread(size, sizeof(int), 2, img);
	gl->texw_me = size[0];
	gl->texh_me = size[1];
	fseek(img, 122, SEEK_SET);
	gl->tex_moi = (int *)malloc(sizeof(int) * (gl->texw_me * gl->texh_me + 1));
	bmp->iter3 = gl->texw_me * gl->texh_me;
	gl->tex_moi[bmp->iter3--] = 0;
	loop_tex_me(bmp, gl, img, gl->tex_moi);
}
