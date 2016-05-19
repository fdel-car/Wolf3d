/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:39:32 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/19 23:09:18 by fdel-car         ###   ########.fr       */
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
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		ang;
	double		camx;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		ftime;
	int			mapx;
	int			mapy;
	int			lineh;
	int			draws;
	int			drawe;
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
int				ft_key_press(t_glob *gl, int keycode);
int				ft_key_release(t_glob *gl, int keycode);
void			ft_map(t_glob *gl);

#endif
