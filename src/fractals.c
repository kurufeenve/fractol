/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:16:19 by vordynsk          #+#    #+#             */
/*   Updated: 2018/05/08 18:16:21 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void    calc(t_general *g, void (*fractal)(t_general *))
{
	g->f.iter = 100;
	g->j = 0;
	g->p = 0;
	if (g->fr_num == 3)
	{
		g->f.scale_x = 3.5 / g->size_x;
		g->f.scale_y = 2.0 / g->size_y;
	}
	while (g->p < g->size_y * g->size_x)
	{
		fractal(g);
		g->p++;
	}
}

void	mandelbrot(t_general *g)
{
	g->f.nr = 0;
	g->f.ni = 0;
	g->f.cr = 1.5 * (g->points[g->p].x - g->size_x / 2) / \
	(g->size_x / 2 * g->f.zoom) + g->f.moX;
	g->f.ci = (g->points[g->p].y - g->size_y / 2) / (g->size_y / 2 * g->f.zoom)\
	+ g->f.moY;
	g->n = 0;
	//printf("nr = %f, ni = %f, or = %f, oi = %f, cr = %f, ci = %f, zoom = %f, moX = %f, moY = %f, iter = %d\n", g->f.nr, g->f.ni, g->f.or, g->f.oi, g->f.cr, g->f.ci, g->f.zoom, g->f.moX, g->f.moY, g->f.iter);
	while (g->n < g->f.iter)
	{
		g->f.or = g->f.nr;
		g->f.oi = g->f.ni;
		g->f.nr = g->f.or * g->f.or - g->f.oi * g->f.oi + g->f.cr;
		g->f.ni = 2 * g->f.or * g->f.oi + g->f.ci;
		//printf("nr = %f, ni = %f, or = %f, oi = %f, cr = %f, ci = %f, check = %f\n", g->f.nr, g->f.ni, g->f.or, g->f.oi, g->f.cr, g->f.ci, g->f.nr * g->f.nr + g->f.ni * g->f.ni);
		if (g->f.nr * g->f.nr + g->f.ni * g->f.ni > 4)
			break ;
		g->n++;
	}
	//ft_color(g);
	g->points[g->p].color.channel[0] = 255 * g->n/g->f.iter + 30;
	g->points[g->p].color.channel[1] = 255 * g->n/g->f.iter + 20;
	g->points[g->p].color.channel[2] = 255 * g->n/g->f.iter + 10;
	g->n == g->f.iter ? g->points[g->p].color.color = 0 : 1;
	//printf("red = %d, green = %d, blue = %d, n = %d, iter = %d, color = %d, bul = %d\n", g->points[g->p].color.channel[0], g->points[g->p].color.channel[1], g->points[g->p].color.channel[2], g->n, g->f.iter, 255 * (g->n / g->f.iter), (int)(g->n < g->f.iter));
	put_pixel(g, g->points[g->p].x, g->points[g->p].y, g->points[g->p].color);
}

void	julia(t_general *g)
{
	g->f.nr = 1.5 * (g->points[g->p].x - g->size_x / 2) / \
	(g->size_x / 2 * g->f.zoom) + g->f.moX;
	g->f.ni = (g->points[g->p].y - g->size_y / 2) / (g->size_y / 2 * g->f.zoom)\
	+ g->f.moY;
	g->n = 0;
	while (g->n < g->f.iter)
	{
		g->f.or = g->f.nr;
		g->f.oi = g->f.ni;
		g->f.nr = g->f.or * g->f.or - g->f.oi * g->f.oi + g->f.cr;
		g->f.ni = 2 * g->f.or * g->f.oi + g->f.ci;
		if (g->f.nr * g->f.nr + g->f.ni * g->f.ni > 4)
			break ;
		g->n++;
	}
	ft_color(g);
	//printf("color = %d, n = %d, iter = %d, color = %d\n", g->points[g->p].color.color, g->n, g->f.iter, (g->n / g->f.iter));
	put_pixel(g, g->points[g->p].x, g->points[g->p].y, g->points[g->p].color);
}

void	ft_color(t_general *g)
{
	g->for_color = (float)g->n / (float)g->f.iter;
	if (g->for_color <= 0.33)
	{
		g->points[g->p].color.channel[2] = 255 * g->for_color;
		g->points[g->p].color.channel[1] = 0;
		g->points[g->p].color.channel[0] = 0;
	}
	else if (g->for_color > 0.33 && g->for_color <= 0.66)
	{
		g->points[g->p].color.channel[2] = 255 * g->for_color;
		g->points[g->p].color.channel[1] = 255 * g->for_color;
		g->points[g->p].color.channel[0] = 0;
	}
	else if (g->for_color > 0.66 && g->for_color < 1)
	{
		g->points[g->p].color.channel[2] = 255 * g->for_color;
		g->points[g->p].color.channel[1] = 255 * g->for_color;
		g->points[g->p].color.channel[0] = 255 * g->for_color;
	}
	else
		g->points[g->p].color.color = 0;
}

void	burning(t_general *g)
{
	g->n = 0;
	g->f.cr = 1.5 * (g->points[g->p].x - g->size_x / 2) / \
	(g->size_x / 2 * g->f.zoom) + g->f.moX;
	g->f.ci = (g->points[g->p].y - g->size_y / 2) / (g->size_y / 2 * g->f.zoom)\
	+ g->f.moY - 0.5;
	g->f.nr = 0;
	g->f.ni = 0;
	//printf("size_x = %d, size_y = %d, scale_x = %f, scale_y = %f, points.x = %f, points.y = %f, nr = %f, ni = %f\n", g->size_x, g->size_y, g->f.scale_x, g->f.scale_y, g->points[g->p].x, g->points[g->p].y, g->f.nr, g->f.ni);
	while (hypot(g->f.nr, g->f.ni) < 4 && g->n < g->f.iter)
	{
		g->f.or = g->f.nr;
		g->f.oi = g->f.ni;
		g->f.nr = fabs(g->f.or) * fabs(g->f.or) - fabs(g->f.oi) * fabs(g->f.oi) + g->f.cr;
		g->f.ni = 2 * fabs(g->f.or) * fabs(g->f.oi) + g->f.ci;
		g->n++;
	}
	ft_color(g);
	//printf("g->n = %d, g->points[g->p].color.channel[0] = %d\n", g->n, g->points[g->p].color.channel[0]);
	put_pixel(g, g->points[g->p].x, g->points[g->p].y, g->points[g->p].color);
}
