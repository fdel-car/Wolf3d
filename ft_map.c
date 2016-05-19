/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 22:32:35 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/19 23:23:32 by fdel-car         ###   ########.fr       */
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
	while (i < gl->size_mapx)
	{
		gl->map[j][i] = ft_atoi(tab[i]);
		i++;
	}
}

void	ft_map(t_glob *gl)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	gl->data = 1;
	gl->fd = open("map", O_RDONLY);
	j = 0;
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
		{
			make_map(gl, j, tab);
			j++;
		}
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}
