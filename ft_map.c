/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 22:32:35 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 17:12:57 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	make_map(t_glob *gl, int j, char **tab)
{
	int	i;

	i = 0;
	if (j == 0)
	{
		gl->map = (int **)malloc(sizeof(int *) * gl->size_mapy);
		if (gl->map == NULL)
			exit(0);
	}
	gl->map[j] = (int *)malloc(sizeof(int) * gl->size_mapx);
	if (gl->map[j] == NULL)
		exit(0);
	while (i < gl->size_mapx)
	{
		gl->map[j][i] = ft_atoi(tab[i]);
		i++;
	}
}

void	ft_setpixel2(t_glob *gl, int x, int y, int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				i;

	if (x > gl->size_mapx * 5 || y > gl->size_mapy * 5 +
			gl->size_mapy / 4 || x < 0 || y < 0)
		return ;
	i = y * gl->sizeline2 + x * gl->bpp2 / 8;
	r = (color & 0xFF);
	g = ((color & 0xFF00) >> 8);
	b = ((color & 0xFF0000) >> 16);
	gl->disp2[i] = r;
	gl->disp2[i + 1] = g;
	gl->disp2[i + 2] = b;
}

void	ft_map(t_glob *gl)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	gl->data = 1;
	gl->fd = open("map", O_RDONLY);
	j = -1;
	while (get_next_line(gl->fd, &str) == 1)
	{
		tab = ft_strsplit(str, ' ');
		if (gl->data == 1)
		{
			gl->size_mapx = ft_atoi(tab[0]);
			gl->size_mapy = ft_atoi(tab[1]);
			gl->data = 0;
		}
		else
			make_map(gl, ++j, tab);
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	close(gl->fd);
}

void	ft_posmap(t_glob *gl)
{
	int i;
	int j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			ft_setpixel2(gl, gl->posy * 5 + j, gl->posx * 5 + i, 0x77B5FE);
			j++;
		}
		i++;
	}
}

void	ft_minimap(t_glob *gl)
{
	char	*str;

	gl->minimap = mlx_new_image(gl->mlx, gl->size_mapx * 5,
			gl->size_mapy * 5 + gl->size_mapy / 4);
	gl->disp2 = mlx_get_data_addr(gl->minimap, &(gl->bpp2), &(gl->sizeline2),
			&(gl->endian2));
	gl->fd = open("map", O_RDONLY);
	gl->mini_y = 0;
	gl->iter = 0;
	if (get_next_line(gl->fd, &str) <= 0)
		return ;
	while (get_next_line(gl->fd, &str) > 0)
	{
		gl->mini_x = 0;
		gl->iter = 0;
		while (str[gl->iter])
		{
			ft_unload(gl, str);
			ft_unload2(gl, str);
		}
		gl->mini_y = gl->mini_y + 5;
	}
	close(gl->fd);
}
