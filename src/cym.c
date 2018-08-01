/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cym.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 04:00:58 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:01:09 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_cyan(t_img *img, int x, int y, int color)
{
	if (color == 0)
		img_set_pixel(img, x, y, 0x3C3C3C);
	else
		img_set_pixel(img, x, y, ((color << 8) & 0x00FF00) | (color & 0xFF));
}

void	draw_magenta(t_img *img, int x, int y, int color)
{
	if (color == 0)
		img_set_pixel(img, x, y, 0x3C3C3C);
	else
		img_set_pixel(img, x, y, ((color << 16) & 0xFF0000) | (color & 0xFF));
}

void	draw_yellow(t_img *img, int x, int y, int color)
{
	if (color == 0)
		img_set_pixel(img, x, y, 0x3C3C3C);
	else
		img_set_pixel(img, x, y, ((color << 16) & 0xFF0000) |
				((color << 8) & 0x00FF00));
}
