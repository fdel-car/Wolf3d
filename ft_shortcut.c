/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 21:04:37 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/19 22:58:04 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_change(t_glob *gl)
{
	mlx_clear_window(gl->mlx, gl->win);
	gl->img = mlx_new_image(gl->mlx, gl->s_x, gl->s_y);
	gl->disp = mlx_get_data_addr(gl->img, &(gl->bpp), &(gl->sizeline),
			&(gl->endian));
}

int		ft_key(int keycode, t_glob *gl)
{
	if (keycode == 53)
		exit(0);
	(void)gl;
	return (0);
}
