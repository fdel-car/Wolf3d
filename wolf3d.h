/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:39:32 by fdel-car          #+#    #+#             */
/*   Updated: 2016/05/18 17:52:06 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

typedef struct	s_glob
{
	int			s_x;
	int			s_y;
	int			wall;
	int			play;
	int			fov;
	int			posx;
	int			posy;
	int			s_g;
	double		h_x;
	double		h_y;
	double		v_x;
	double		v_y;
	double		xa;
	double		ya;
	double		ang;
	double		sray;
	double		beta;
	int			he_w;
	int			pov;
	int			dpp;
	void		*mlx;
	void		*win;
	void		*img;
	char		*disp;
	int			bpp;
	int			sizeline;
	int			endian;
	int			**map;
	int			color;
	int			draws;
	int			drawe;
	double		d_h;
	double		d_v;
	double		dist;
}				t_glob;

void			ft_verline(int x, t_glob *gl);
int				ft_key(int keycode, t_glob *gl);
void			ft_detect_wall(t_glob *gl);
int				**ft_map(void);

#endif
