/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftype_brot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 04:01:16 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:01:28 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	is_mendelbrot_set(t_complex *c, double x, double y, t_fractal *fr)
{
	t_complex	old;
	t_complex	new;
	t_complex	cn;
	int			i;

	(void)c;
	i = -1;
	cn = get_pixel_value(x, y, fr);
	new.real = 0;
	new.imag = 0;
	while (++i < fr->max_iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		old.rsqr = old.real * old.real;
		old.isqr = old.imag * old.imag;
		new.real = old.rsqr - old.isqr + cn.real;
		new.imag = (old.real + old.real) * old.imag + cn.imag;
		new.rsqr = new.real * new.real;
		new.isqr = new.imag * new.imag;
		if ((new.rsqr + new.isqr) > 4)
			return (i);
	}
	return (0);
}

int	rev_mendelbrot_set(t_complex *c, double x, double y, t_fractal *fr)
{
	t_complex	old;
	t_complex	new;
	t_complex	cn;
	int			i;

	(void)c;
	i = -1;
	cn = get_pixel_value(x, y, fr);
	new.real = 0;
	new.imag = 0;
	while (++i < fr->max_iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		old.rsqr = old.real * old.real;
		old.isqr = old.imag * old.imag;
		new.real = old.rsqr - old.isqr + cn.real;
		new.imag = (old.real + old.real) * old.imag + cn.imag;
		new.rsqr = new.real * new.real;
		new.isqr = new.imag * new.imag;
		if ((new.rsqr + new.isqr) > 4)
			return (sqrt(new.rsqr + new.isqr) + i);
	}
	return (0);
}

int	is_burningship(t_complex *c, double x, double y, t_fractal *fr)
{
	t_complex	old;
	t_complex	new;
	t_complex	cn;
	int			i;

	(void)c;
	i = -1;
	cn = get_pixel_value(x, y, fr);
	new.real = 0;
	new.imag = 0;
	while (++i < fr->max_iter)
	{
		old.real = new.real;
		old.imag = new.imag;
		old.rsqr = old.real * old.real;
		old.isqr = old.imag * old.imag;
		new.real = fabs(old.rsqr - old.isqr) + cn.real;
		new.imag = fabs(old.real + old.real) * fabs(old.imag) + cn.imag;
		new.rsqr = new.real * new.real;
		new.isqr = new.imag * new.imag;
		if ((new.rsqr + new.isqr) > 4)
			return (i);
	}
	return (0);
}
