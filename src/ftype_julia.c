/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftype_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 04:01:31 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:01:39 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	is_julia_set(t_complex *c, double x, double y, t_fractal *fr)
{
	t_complex	old;
	t_complex	new;
	int			i;

	i = 0;
	new = get_pixel_value(x, y, fr);
	while (i < fr->max_iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		old.rsqr = old.real * old.real;
		old.isqr = old.imag * old.imag;
		new.real = old.rsqr - old.isqr + c->real;
		new.imag = (old.real + old.real) * old.imag + c->imag;
		new.rsqr = new.real * new.real;
		new.isqr = new.imag * new.imag;
		if ((new.rsqr + new.isqr) > 4)
			return (i);
		i++;
	}
	return (0);
}

int	rev_julia_set(t_complex *c, double x, double y, t_fractal *fr)
{
	t_complex	old;
	t_complex	new;
	int			i;

	i = 0;
	new = get_pixel_value(x, y, fr);
	while (i < fr->max_iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		old.rsqr = old.real * old.real;
		old.isqr = old.imag * old.imag;
		new.real = old.rsqr - old.isqr + c->real;
		new.imag = (old.real + old.real) * old.imag + c->imag;
		new.rsqr = new.real * new.real;
		new.isqr = new.imag * new.imag;
		if ((new.rsqr + new.isqr) > 4)
			return (sqrt(new.rsqr + new.isqr));
		i++;
	}
	return (0);
}

int	is_fishbone(t_complex *c, double x, double y, t_fractal *fr)
{
	t_complex	old;
	t_complex	new;
	int			i;

	i = 0;
	new = get_pixel_value(x, y, fr);
	while (i < fr->max_iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		old.rsqr = old.real * old.real;
		old.isqr = old.imag * old.imag;
		new.real = old.rsqr - old.isqr + old.real + c->real;
		new.imag = -(old.real + old.real) * old.imag + old.imag + c->imag;
		new.rsqr = new.real * new.real;
		new.isqr = new.imag * new.imag;
		if ((new.rsqr + new.isqr) > 4)
			return (sqrt(new.rsqr + new.isqr) + (i << 4));
		i++;
	}
	return (0);
}
