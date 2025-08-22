/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:55:22 by aalqanta          #+#    #+#             */
/*   Updated: 2025/08/21 01:15:03 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_mandel(t_app *app)
{
	int	x;
	int	y;
	int	n;
	t_c	z;

	y = 0;
	while (y < app->img.w)
	{
		x = 0;
		while (x < app->img.h)
		{
			z = pixel_to_complex(app, x, y);
			n = it_mandel(z, app->max_iter);
			put_px(&app->img, x, y, colorit(n, app->max_iter));
			x++;
		}
		y++;
	}
}

static void	draw_julia(t_app *app)
{
	int	y;
	int	x;
	int	n;
	t_c	c;
	t_c	z;

	y = 0;
	while (y < app->img.w)
	{
		x = 0;
		while (x < app->img.h)
		{
			z = pixel_to_complex(app, x, y);
			c.re = app->c_re;
			c.im = app->c_im;
			n = it_julia(z, c, app->max_iter);
			put_px(&app->img, x, y, colorit(n, app->max_iter));
			x++;
		}
		y++;
	}
}

void	render(t_app *app)
{
	if (app->type == 1)
		draw_mandel(app);
	else if (app->type == 2)
		draw_julia(app);
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
}
