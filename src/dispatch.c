/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 03:02:41 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:32:19 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_fn_fract		*dispatch_fract(void)
{
	t_fn_fract	*f_type;

	f_type = (t_fn_fract *)malloc(sizeof(t_fn_fract) * 7);
	f_type[0] = is_julia_set;
	f_type[1] = is_mendelbrot_set;
	f_type[2] = is_fishbone;
	f_type[3] = rev_julia_set;
	f_type[4] = rev_mendelbrot_set;
	f_type[5] = is_burningship;
	f_type[6] = NULL;
	return (&*f_type);
}

t_draw_method	*dispatch_draw(void)
{
	t_draw_method *d_type;

	d_type = (t_draw_method *)malloc(sizeof(t_draw_method) * 7);
	d_type[0] = draw_red;
	d_type[1] = draw_green;
	d_type[2] = draw_blue;
	d_type[3] = draw_cyan;
	d_type[4] = draw_magenta;
	d_type[5] = draw_yellow;
	d_type[6] = NULL;
	return (d_type);
}
