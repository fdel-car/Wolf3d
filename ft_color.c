/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 17:31:11 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/20 21:30:48 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_color(t_glob *gl)
{
	gl->color = 0xFF0000;
	if (gl->map[gl->mapx][gl->mapy] == 3)
	{
		if (gl->side == 0)
		{
			if (gl->stepx < 0)
				gl->color = 0x5B3C11;
			else
				gl->color = 0xA76726;
		}
		else
		{
			if (gl->stepy < 0)
				gl->color = 0x8B6C42;
			else
				gl->color = 0x7E5835;
		}
	}
}
