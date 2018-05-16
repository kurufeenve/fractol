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
	g->f.iter = 255;
	g->j = 0;
	g->p = 0;
	while (g->p < g->size_y * g->size_x)
	{
		fractal(g);
		g->p++;
	}
}

void	mandelbrot(t_general *g)
{
	g->f.zoom = 1;
	g->f.moX = -0.5;
	g->f.moY = 0;
	g->f.cr = 1.5 * (g->i - g->size_x / 2) / \
	(g->size_x / 2 * g->f.zoom) + g->f.moX;
	g->f.ci = (g->j - g->size_y / 2) / (g->size_y / 2 * g->f.zoom);
	g->n = 0;
	while (g->n < g->f.iter)
	{
		g->f.or = g->f.nr;
		g->f.oi = g->f.ni;
		g->f.nr = g->f.or * g->f.or - g->f.oi * g->f.oi + g->f.cr;
		g->f.ni = 2 * g->f.or * g->f.oi + g->f.ci;
		printf("nr %f ni %f\n", g->f.nr, g->f.ni);
		if (g->f.nr * g->f.nr + g->f.ni * g->f.ni > 4)
			break ;
		g->n++;
	}
	g->points[g->p].color.channel[0] = g->n * (g->n < g->f.iter);
	g->points[g->p].color.channel[1] = g->n;
	g->points[g->p].color.channel[2] = g->n;
	printf("\n\n\ng->n = %d, x = %f, y = %f\n", g->n, g->points[g->p].x, g->points[g->p].y);
	put_pixel(g, g->points[g->p].x, g->points[g->p].y, g->points[g->p].color);
}
