/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalqanta <aalqanta@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 18:54:25 by aalqanta          #+#    #+#             */
/*   Updated: 2025/08/21 00:31:57 by aalqanta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct s_img
{
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
	void	*img;
	char	*addr;
}	t_img;

typedef struct s_app
{
	int		type;
	int		max_iter;
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	c_re;
	double	c_im;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}	t_app;

typedef struct s_c
{
	double	re;
	double	im;
}	t_c;

int		on_mouse(int button, int x, int y, t_app *app);
int		on_key(int key, t_app *app);
int		on_close(t_app *app);
int		app_init(t_app *app, int w, int h);
int		app_destroy(t_app *app);
int		it_mandel(t_c c, int max_it);
int		it_julia(t_c z0, t_c c, int max_it);
int		str_eq(const char *a, const char *b);
int		colorit(int n, int max_it);
void	putstr_fd(const char *s);
double	atodbl(char *s);
void	view_reset(t_app *app);
void	put_px(t_img *img, int x, int y, unsigned int color);
void	render(t_app *app);
t_c		pixel_to_complex(t_app *app, int x, int y);

#endif
