/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:39:32 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/27 17:27:00 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
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
	double		wallx;
	int			mini_x;
	int			mini_y;
	int			tex_x;
	int			tex_y;
	int			texw;
	int			texh;
	int			texw_s;
	int			texh_s;
	int			texw_me;
	int			texh_me;
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
	void		*minimap;
	char		*disp;
	char		*disp2;
	int			iter;
	int			bpp;
	int			bpp2;
	int			sizeline;
	int			sizeline2;
	int			endian;
	int			endian2;
	int			color;
	int			temp;
	int			temp2;
	int			temp3;
	int			temp4;
	int			**map;
	int			*tex_grey;
	int			*tex_wood;
	int			*tex_sky;
	int			*tex_moi;
}				t_glob;

typedef	struct	s_bitmap
{
	int		iter;
	int		iter2;
	int		iter3;
}				t_bitmap;

void			ft_verline(int x, t_glob *gl);
void			ft_detect_wall(t_glob *gl);
int				ft_key_press(int keycode, t_glob *gl);
int				ft_key_release(int keycode, t_glob *gl);
void			ft_move_rot(t_glob *gl);
int				ft_close(t_glob *gl);
void			ft_map(t_glob *gl);
void			ft_minimap(t_glob *gl);
void			ft_color(t_glob *gl);
void			texture_grey(t_glob *gl, t_bitmap *bmp);
void			texture_me(t_glob *gl, t_bitmap *bmp);
void			ft_init_raycast(t_glob *gl);
void			ft_rayhandle(t_glob *gl);
void			dda(t_glob *gl);
void			handle_wall(t_glob *gl);
void			texture_wood(t_glob *gl, t_bitmap *bmp);
void			ft_setpixel2(t_glob *gl, int x, int y, int color);
void			ft_posmap(t_glob *gl);
void			ft_skybox(t_glob *gl, t_bitmap *bmp);
void			ft_unload(t_glob *gl, char *str);
void			ft_unload2(t_glob *gl, char *str);
void			loop_tex_me(t_bitmap *bmp, t_glob *gl, FILE *img, int *tex);

#endif
