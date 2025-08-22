/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:54:53 by aalqanta          #+#    #+#             */
/*   Updated: 2025/08/21 16:35:33 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	putstr_fd("usage: \n");
	putstr_fd("\t./fractol mandelbrot\n");
	putstr_fd("\t./fractol julia <re> <im>\n");
}

static int	check_input(t_app *app, int argc, char **argv)
{
	if (argc < 2)
		return (1);
	if ((argc == 2 && str_eq(argv[1], "mandelbrot"))
		|| (argc == 4 && str_eq(argv[1], "julia")))
	{
		app->name = argv[1];
		if (str_eq(argv[1], "julia"))
		{
			app->c_re = atodbl(argv[2]);
			app->c_im = atodbl(argv[3]);
			app->type = 2;
		}
		else
			app->type = 1;
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;

	if (check_input(&app, argc, argv))
	{
		usage();
		return (0);
	}
	app.img.w = 800;
	app.img.h = 800;
	if (app_init(&app, app.img.w, app.img.h))
		return (1);
	render(&app);
	mlx_hook(app.win, 17, 0, on_close, &app);
	mlx_key_hook(app.win, on_key, &app);
	mlx_mouse_hook(app.win, on_mouse, &app);
	mlx_loop(app.mlx);
	return (0);
}
