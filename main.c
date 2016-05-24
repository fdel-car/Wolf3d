/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:38:43 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/24 21:19:18 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

void	ft_init(t_glob *gl)
{
	ft_map(gl);
	gl->s_x = 1280;
	gl->s_y = 720;
	gl->posx = 20;
	gl->posy = 2;
	gl->dirx = -1;
	gl->diry = 0;
	gl->planex = 0;
	gl->planey = 0.66;
	gl->oldtime = 0;
	gl->time = 0;
	gl->move_right = 0;
	gl->move_left = 0;
	gl->move_front = 0;
	gl->move_back = 0;
	gl->rot_left = 0;
	gl->rot_right = 0;
	gl->sprint = 0;
}

void	ft_detect_wall(t_glob *gl)
{
	int x;

	x = 0;
	while (x < gl->s_x)
	{
		gl->camx = 2 * x / (double)gl->s_x - 1;
		ft_init_raycast(gl);
		ft_rayhandle(gl);
		dda(gl);
		handle_wall(gl);
		ft_verline(x, gl);
		x++;
	}
	gl->oldtime = gl->time;
	gl->time = clock();
	gl->ftime = (gl->time - gl->oldtime) / CLOCKS_PER_SEC;
	gl->ms = gl->ftime * 5.0;
	gl->rs = gl->ftime * 3.0;
	mlx_put_image_to_window(gl->mlx, gl->win, gl->img, 0, 0);
	mlx_destroy_image(gl->mlx, gl->img);
	mlx_string_put(gl->mlx, gl->win, 20, 20, 0xFFFFFF, "FPS : ");
	mlx_string_put(gl->mlx, gl->win, 80, 20, 0xFFFFFF,
			ft_itoa(1.0 / gl->ftime));
}

int		ft_wolf3d(t_glob *gl)
{
	gl->img = mlx_new_image(gl->mlx, gl->s_x, gl->s_y);
	gl->disp = mlx_get_data_addr(gl->img, &(gl->bpp), &(gl->sizeline),
			&(gl->endian));
	ft_move_rot(gl);
	ft_detect_wall(gl);
	if (gl->sprint)
		gl->ms = gl->ms * 2;
	return (0);
}

int		ft_close(t_glob *gl)
{
	int i;

	i = 0;
	while (i < gl->size_mapy)
		free(gl->map[i++]);
	free(gl->map);
	free(gl->tex_grey);
	free(gl->tex_wood);
	free(gl);
	exit(0);
}

int		main(void)
{
	t_glob		*gl;
	t_bitmap	*bmp;

	gl = (t_glob *)malloc(sizeof(t_glob));
	bmp = (t_bitmap *)malloc(sizeof(t_bitmap));
	ft_init(gl);
	texture_grey(gl, bmp);
	texture_wood(gl, bmp);
	gl->mlx = mlx_init();
	gl->win = mlx_new_window(gl->mlx, gl->s_x, gl->s_y, "Wolf 3D");
	ft_wolf3d(gl);
	mlx_loop_hook(gl->mlx, ft_wolf3d, gl);
	mlx_hook(gl->win, 2, (1L << 0), ft_key_press, gl);
	mlx_hook(gl->win, 3, (1L << 1), ft_key_release, gl);
	mlx_hook(gl->win, 17, 0, ft_close, gl);
	mlx_loop(gl->mlx);
	return (0);
}
