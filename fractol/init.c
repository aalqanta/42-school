/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:54:44 by aalqanta          #+#    #+#             */
/*   Updated: 2025/08/20 19:40:17 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	app_init(t_app *app, int w, int h)
{
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, w, h, app->name);
	app->img.img = mlx_new_image(app->mlx, w, h);
	app->img.addr = mlx_get_data_addr(app->img.img, &app->img.bpp,
			&app->img.line_len, &app->img.endian);
	if (!app->mlx || !app->win || !app->img.img || !app->img.addr)
		return (1);
	view_reset(app);
	return (0);
}

void	view_reset(t_app *app)
{
	app->xmin = -2.0;
	app->xmax = 2.0;
	app->ymin = -1.5;
	app->ymax = 1.5;
	app->max_iter = 100;
}

int	app_destroy(t_app *app)
{
	if (app->img.img)
		mlx_destroy_image(app->mlx, app->img.img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free (app->mlx);
	}
	exit (0);
	return (0);
}
