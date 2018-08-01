/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 19:20:19 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:02:06 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		get_draw_method(t_fractal *fr, int c_type)
{
	if (c_type > 0 && c_type < 7)
		fr->draw_type = c_type;
	else
		fr->draw_type = 0;
}

void		set_algo(t_mlx *mlx, int f_type)
{
	if (f_type > 0 && f_type < 7)
		mlx->fract_type = f_type;
	else
		mlx->fract_type = 0;
}

t_fractal	*make_fractal(int iter, t_complex *c)
{
	t_fractal *f;

	if (!(f = (t_fractal*)malloc(sizeof(t_fractal))))
		return (NULL);
	f->max_iter = iter;
	f->c = c;
	f->x_off = 0;
	f->y_off = 0;
	f->context = 1.0;
	return (f);
}

t_complex	*get_complex_number(double r, double im)
{
	t_complex *c;

	if (!(c = (t_complex *)malloc(sizeof(t_complex))))
		return (NULL);
	c->real = r;
	c->imag = im;
	return (c);
}
