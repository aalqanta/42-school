/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:55:09 by aalqanta          #+#    #+#             */
/*   Updated: 2025/08/21 01:06:00 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_c	pixel_to_complex(t_app *app, int x, int y)
{
	t_c		z;
	double	tx;
	double	ty;

	tx = (double)x / (double)(app->img.w - 1);
	ty = (double)y / (double)(app->img.h - 1);
	z.re = app->xmin + (app->xmax - app->xmin) * tx;
	z.im = app->ymax - (app->ymax - app->ymin) * ty;
	return (z);
}

void	put_px(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	it_mandel(t_c c, int max_it)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0.0;
	zi = 0.0;
	n = 0;
	while (n < max_it && (zr * zr + zi * zi) <= 4.0)
	{
		tmp = zr * zr - zi * zi + c.re;
		zi = 2.0 * zr * zi + c.im;
		zr = tmp;
		n++;
	}
	return (n);
}

int	it_julia(t_c z0, t_c c, int max_it)
{
	int		n;
	double	tmp;
	double	zr;
	double	zi;

	n = 0;
	zr = z0.re;
	zi = z0.im;
	while (n < max_it && (zr * zr + zi * zi) <= 4.0)
	{
		tmp = zr * zr - zi * zi + c.re;
		zi = 2.0 * zr * zi + c.im;
		zr = tmp;
		n++;
	}
	return (n);
}

int	colorit(int n, int max_it)
{
	unsigned int	base[15];

	base[0] = 0x000000;
	base[1] = 0x1A051A;
	base[2] = 0x480355;
	base[3] = 0x8D0694;
	base[4] = 0xCC08C2;
	base[5] = 0xE1029F;
	base[6] = 0xF5066F;
	base[7] = 0xEF0202;
	base[8] = 0xF05A02;
	base[9] = 0xF87F04;
	base[10] = 0xFEAA03;
	base[11] = 0xFFDC00;
	base[12] = 0xDAFF05;
	base[13] = 0x00FF00;
	base[14] = 0xFFFFFF;
	if (n >= max_it)
		return (0x000000);
	return (base[n % 15]);
}
