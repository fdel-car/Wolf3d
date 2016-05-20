/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 21:04:37 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/20 20:26:41 by fdel-car         ###   ########.fr       */
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

int		ft_key_press(int keycode, t_glob *gl)
{
	if (keycode == 257)
		gl->sprint = 1;
	if (keycode == 53)
		ft_close(gl);
	if (keycode == 13)
		gl->move_front = 1;
	if (keycode == 0)
		gl->move_left = 1;
	if (keycode == 1)
		gl->move_back = 1;
	if (keycode == 2)
		gl->move_right = 1;
	if (keycode == 123)
		gl->rot_left = 1;
	if (keycode == 124)
		gl->rot_right = 1;
	return (0);
}

int		ft_key_release(int keycode, t_glob *gl)
{
	if (keycode == 257)
		gl->sprint = 0;
	if (keycode == 0)
		gl->move_left = 0;
	if (keycode == 1)
		gl->move_back = 0;
	if (keycode == 13)
		gl->move_front = 0;
	if (keycode == 2)
		gl->move_right = 0;
	if (keycode == 123)
		gl->rot_left = 0;
	if (keycode == 124)
		gl->rot_right = 0;
	return (0);
}
