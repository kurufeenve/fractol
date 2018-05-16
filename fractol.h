/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 19:05:44 by vordynsk          #+#    #+#             */
/*   Updated: 2018/05/03 19:05:46 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include "libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>

typedef union		s_color
{
	int				color;
	unsigned char	channel[4];
}					t_color;

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	t_color			color;
}					t_point;

typedef struct		s_fractal
{
	double			nr;
	double			ni;
	double			or;
	double			oi;
	double			cr;
	double			ci;
	double			zoom;
	double			moX;
	double			moY;
	int				iter;
	int				col;
}					t_fractal;

typedef struct		s_general
{
	void			*init;
	void			*win;
	int				size_x;
	int				size_y;
	void			*img;
	char			*image;
	int				bpp;
	int				val;
	int				ed;
	t_point			*points;
	t_color			color;
	int				i;
	int				j;
	int				n;
	int				p;
	t_fractal		f;
}               	t_general;

int					exit_x(void);
int					key_hook(int key, void *ptr);
void				put_pixel(t_general *g, int x, int y, t_color color);
void				map(t_general *g);
void				calc(t_general *g, void fractal(t_general *g));
void				mandelbrot(t_general *g);
void				ft_clearscr(t_general *gen);
void				ft_screen_stuff(t_general *g);

#endif

