/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:37:36 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:30:07 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include <stdlib.h>
# include <stddef.h>
# include <pthread.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "keys.h"
# include "../minilibx_macos/mlx.h"

# define WIN_W 1600
# define WIN_H 912
# define HALF_W 800
# define HALF_H 456

typedef	struct		s_complex
{
	double			real;
	double			imag;
	double			rsqr;
	double			isqr;
}					t_complex;

typedef	struct		s_img
{
	void			*img;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_img;

typedef	void		(*t_draw_method)(t_img *, int, int, int);

typedef struct		s_fractal
{
	int				max_iter;
	t_complex		*c;
	double			x_off;
	double			y_off;
	double			context;
	int				draw_type;

}					t_fractal;

typedef struct		s_mouse
{
	double			x;
	double			y;
	double			prev_x;
	double			prev_y;
	unsigned char	is_down;
}					t_mouse;

typedef	int			(*t_fn_fract)(t_complex *, double, double, t_fractal *fr);

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_fractal		*frac;
	t_mouse			*mouse;
	int				color_method;
	int				fract_type;
	t_fn_fract		*f_dispatch;
	t_draw_method	*d_dispatch;
}					t_mlx;

typedef struct		s_argp
{
	t_mlx			*mlx;
	int				thread_i;
}					t_argp;

/*
** util.c
*/
void				get_draw_method(t_fractal *fr, int c_type);
void				set_algo(t_mlx *mlx, int f_type);
t_fractal			*make_fractal(int iter, t_complex *c);
t_complex			*get_complex_number(double r, double im);

/*
** render.c
*/
int					render(t_mlx *mlx);
void				reset(t_mlx *mlx);
t_complex			get_pixel_value(double x, double y, t_fractal *fr);

/*
** draw_methods
*/
void				draw_red(t_img *img, int x, int y, int color);
void				draw_green(t_img *img, int x, int y, int color);
void				draw_blue(t_img *img, int x, int y, int color);
void				draw_magenta(t_img *img, int x, int y, int color);
void				draw_cyan(t_img *img, int x, int y, int color);
void				draw_yellow(t_img *img, int x, int y, int color);
void				get_draw_method(t_fractal *fr, int choice);

/*
** img.c
*/
t_img				*del_img(t_mlx *mlx, t_img *img);
void				clear_img(t_img *img);
t_img				*new_img(t_mlx *mlx);
void				img_set_pixel(t_img *img, int x, int y, int color);

/*
** fractal_types.c
*/
int					is_julia_set(t_complex *c, double x,
									double y, t_fractal *fr);
int					is_mendelbrot_set(t_complex *c, double x,
									double y, t_fractal *fr);
int					is_fishbone(t_complex *c, double x,
									double y, t_fractal *fr);
int					is_burningship(t_complex *c, double x,
									double y, t_fractal *fr);
int					rev_julia_set(t_complex *c, double x,
									double y, t_fractal *fr);
int					rev_mendelbrot_set(t_complex *c, double x,
									double y, t_fractal *fr);
/*
** mouse.c
*/
int					hook_mousedown(int	button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);

/*
** hooks.c
*/
int					hook_key_pressed(int key, t_mlx *mlx);
int					hook_key_down(int key, t_mlx *mlx);

void				set_algo(t_mlx *mlx, int f_type);
/*
** DISPATCH TABLE STUFF
*/

t_fn_fract			*dispatch_fract(void);
t_draw_method		*dispatch_draw(void);
#endif
