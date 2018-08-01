/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 04:01:55 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 04:02:04 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_red(t_img *img, int x, int y, int color)
{
	if (color == 0)
		img_set_pixel(img, x, y, 0x3C3C3C);
	else
		img_set_pixel(img, x, y, ((color << 16) & 0xFFFFFF));
}

void	draw_green(t_img *img, int x, int y, int color)
{
	if (color == 0)
		img_set_pixel(img, x, y, 0x3C3C3C);
	else
		img_set_pixel(img, x, y, ((color << 8) & 0xFFFFFF));
}

void	draw_blue(t_img *img, int x, int y, int color)
{
	if (color == 0)
		img_set_pixel(img, x, y, 0x3C3C3C);
	else
		img_set_pixel(img, x, y, color & 0xFFFFFF);
}
