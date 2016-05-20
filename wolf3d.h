/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:39:32 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/20 20:26:54 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_glob
{
	int			s_x;
	int			s_y;
	double		posx;
	double		posy;
	double		dirx;
	double		olddirx;
	double		diry;
	double		planex;
	double		oldplanex;
	double		planey;
	double		time;
	double		oldtime;
	double		camx;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		ftime;
	int			sprint;
	int			mapx;
	int			mapy;
	int			lineh;
	int			draws;
	int			drawe;
	int			move_right;
	int			move_left;
	int			move_back;
	int			move_front;
	int			rot_right;
	int			rot_left;
	double		sdistx;
	double		sdisty;
	double		ddistx;
	double		ddisty;
	double		pwd;
	double		ms;
	double		rs;
	int			data;
	int			fd;
	int			size_mapx;
	int			size_mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	void		*mlx;
	void		*win;
	void		*img;
	char		*disp;
	int			bpp;
	int			sizeline;
	int			endian;
	int			color;
	int			**map;
}				t_glob;

void			ft_verline(int x, t_glob *gl);
void			ft_detect_wall(t_glob *gl);
int				ft_key_press(int keycode, t_glob *gl);
int				ft_key_release(int keycode, t_glob *gl);
void			ft_move_rot(t_glob *gl);
int				ft_close(t_glob *gl);
void			ft_map(t_glob *gl);
void			ft_color(t_glob *gl);

#endif
