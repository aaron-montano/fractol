/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:24:18 by amontano          #+#    #+#             */
/*   Updated: 2018/07/30 03:54:06 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include <limits.h>

t_mlx		*mlx_dispose(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->img)
		del_img(mlx, mlx->img);
	if (mlx->mouse)
		ft_memdel((void **)&mlx->mouse);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init(void)
{
	t_mlx *mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init()) \
		|| (!(mlx->win = mlx_new_window(mlx->mlx, WIN_W, WIN_H, "Fract'ol"))) \
		|| (!(mlx->img = new_img(mlx)))
		|| (!(mlx->mouse = (t_mouse *)malloc(sizeof(t_mouse)))))
	{
		perror("mlx failed to init");
		return (mlx_dispose(mlx));
	}
	return (mlx);
}

void		go_fishing(t_mlx *mlx)
{
	mlx->f_dispatch = dispatch_fract();
	mlx->d_dispatch = dispatch_draw();
	mlx->mouse->is_down = 0;
	mlx_hook(mlx->win, 2, 0, hook_key_pressed, mlx);
	mlx_hook(mlx->win, 3, 0, hook_key_down, mlx);
	mlx_hook(mlx->win, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mousemove, mlx);
	mlx_loop_hook(mlx->mlx, &render, mlx);
	mlx_loop(mlx->mlx);
}

void		show_usage(void)
{
	ft_putstr("usage: ./fractol [1 - 6] [1 - 6]\n");
	ft_putstr("6 fractal types, 6 color schemes\n");
}

int			main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_complex	*c;
	int			type;

	if (argc < 2 || argc > 3 || ((mlx = init()) == NULL))
	{
		show_usage();
		exit(1);
	}
	if (argc == 2 || argc == 3)
	{
		type = (ft_isdigit((int)*argv[1]) ? ft_atoi(argv[1]) - 1 : 0);
		c = get_complex_number(0.61803398875, 0.00);
		mlx->frac = make_fractal(10, c);
		set_algo(mlx, type);
		if (argc == 3)
		{
			type = (ft_isdigit((int)*argv[2]) ? ft_atoi(argv[2]) - 1 : 0);
			get_draw_method(mlx->frac, type);
		}
		else
			mlx->frac->draw_type = 0;
	}
	go_fishing(mlx);
	return (0);
}
