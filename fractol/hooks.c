/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:54:35 by aalqanta          #+#    #+#             */
/*   Updated: 2025/08/21 01:04:39 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_at(t_app *app, double cx, double cy, double factor)
{
	double	w;
	double	h;

	w = (app->xmax - app->xmin) * factor;
	h = (app->ymax - app->ymin) * factor;
	app->xmin = cx - w * 0.5;
	app->xmax = cx + w * 0.5;
	app->ymin = cy - h * 0.5;
	app->ymax = cy + h * 0.5;
	if (factor < 1.0 && app->max_iter < 1000)
		app->max_iter += 5;
}

int	on_mouse(int button, int x, int y, t_app *app)
{
	t_c	center;

	if (button != 4 && button != 5)
		return (0);
	center = pixel_to_complex(app, x, y);
	if (button == 4)
		zoom_at(app, center.re, center.im, 0.8);
	if (button == 5)
		zoom_at(app, center.re, center.im, 1.3);
	render(app);
	return (0);
}

int	on_key(int key, t_app *app)
{
	if (key == 65307)
		on_close(app);
	if (key == 32)
	{
		view_reset (app);
		render(app);
	}
	return (0);
}

int	on_close(t_app *app)
{
	return (app_destroy(app));
}
