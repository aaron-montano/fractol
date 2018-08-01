/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 12:58:45 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 03:10:05 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_complex	get_pixel_value(double x, double y, t_fractal *fr)
{
	t_complex	val;

	val.real = 1.5 *
		(x - HALF_W) / (HALF_W * fr->context) + fr->x_off;
	val.imag = (y - HALF_H) / (HALF_H * fr->context) + fr->y_off;
	return (val);
}

void		reset(t_mlx *mlx)
{
	mlx->frac->x_off = 0;
	mlx->frac->y_off = 0;
	mlx->mouse->is_down = 0x0;
	mlx->frac->context = 1;
	mlx->frac->max_iter = 10;
}

void		*rend_thread(void *param)
{
	int		y;
	int		x;
	int		color;
	t_argp	*argp;
	int		i;

	i = 0;
	argp = (t_argp *)param;
	y = argp->thread_i;
	while (i < (WIN_H >> 4))
	{
		x = 0;
		while (x < WIN_W)
		{
			color =
			argp->mlx->f_dispatch[argp->mlx->fract_type](argp->mlx->frac->c, \
					x, y, argp->mlx->frac);
			argp->mlx->d_dispatch[argp->mlx->frac->draw_type](argp->mlx->img, \
					x, y, color);
			x++;
		}
		y += 16;
		i++;
	}
	pthread_exit(0);
}

int			render(t_mlx *mlx)
{
	pthread_t	thread_id[16];
	t_argp		argp[16];
	int			i;

	i = 0;
	clear_img(mlx->img);
	while (i < 16)
	{
		argp[i].mlx = mlx;
		argp[i].thread_i = i;
		pthread_create(&thread_id[i], NULL, rend_thread, &argp[i]);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	return (0);
}
