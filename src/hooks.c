/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:00:17 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 03:42:07 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	hook_key_down(int key, t_mlx *mlx)
{
	if (key == KEY_SPACE)
		mlx->mouse->is_down ^= (0x10);
	if (key == KEY_F)
		mlx->mouse->is_down ^= (0x20);
	if (key == 42)
		reset(mlx);
	return (0);
}

int	hook_key_pressed(int key, t_mlx *mlx)
{
	if (key == KEY_NUM_MINUS && (mlx->frac->max_iter > 0))
		mlx->frac->max_iter -= 10;
	if (key == KEY_NUM_PLUS)
		mlx->frac->max_iter += 10;
	if (key == KEY_S)
		mlx->frac->context /= 1.0125;
	if (key == KEY_W)
		mlx->frac->context *= 1.0125;
	if ((key == KEY_A) && (mlx->frac->max_iter > 0))
		mlx->frac->max_iter--;
	if (key == KEY_D)
		mlx->frac->max_iter++;
	if (key >= KEY_NUM_1 && key <= KEY_NUM_6)
		set_algo(mlx, key - KEY_NUM_1);
	if (key >= KEY_1 && key <= KEY_5)
		get_draw_method(mlx->frac, key - KEY_1);
	if (key == KEY_ESC)
		exit(0);
	return (0);
}
