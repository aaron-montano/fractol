/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 23:42:24 by amontano          #+#    #+#             */
/*   Updated: 2018/07/31 21:57:35 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	if (button == 4)
		mlx->frac->context *= 1.0125;
	if (button == 5)
		mlx->frac->context /= 1.0125;
	if (button == 3)
	{
		mlx->frac->x_off += 1.5 * (x - HALF_W) / (HALF_W * mlx->frac->context);
		mlx->frac->y_off += (y - HALF_H) / (HALF_H * mlx->frac->context);
	}
	if (button < 4)
		mlx->mouse->is_down |= (1 << button);
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->is_down &= ((mlx->mouse->is_down & 0x30) | ~(1 << button));
	return (0);
}

void	hook_mousemove_2(int x, int y, t_mlx *mlx)
{
	if ((mlx->mouse->is_down & 0x10) && !(mlx->mouse->is_down & 0x02))
	{
		mlx->frac->x_off +=
		(1.5 * (x - HALF_W) / (HALF_W * mlx->frac->context)) - mlx->frac->x_off;
		mlx->frac->y_off +=
		((y - HALF_H) / (HALF_H * mlx->frac->context)) - mlx->frac->y_off;
	}
	if ((mlx->mouse->is_down & 0x20) || (mlx->mouse->is_down & 0x04))
	{
		mlx->frac->c->real += 0.00025 *
			(double)(mlx->mouse->prev_y - y) / mlx->frac->context;
		mlx->frac->c->imag += 0.00025 *
			(double)(mlx->mouse->prev_x - x) / mlx->frac->context;
	}
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->is_down & 0x02)
	{
		mlx->frac->x_off +=
		(1.5 * (mlx->mouse->prev_x - HALF_W) / (HALF_W * mlx->frac->context)) \
		- (1.5 * (x - HALF_W) / (HALF_W * mlx->frac->context));
		mlx->frac->y_off +=
		((mlx->mouse->prev_y - HALF_H) / (HALF_H * mlx->frac->context)) \
		- ((y - HALF_H) / (HALF_H * mlx->frac->context));
	}
	hook_mousemove_2(x, y, mlx);
	return (0);
}
