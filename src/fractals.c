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

void    mandelbrot(t_general *g)
{
	g->f.iter = 200;
	g->j = 0;
	g->p = 0;
	while (g->j < g->size_y)
	{
		g->i = 0;
		while (g->i < g->size_x)
		{
			calc(g);
			g->i++;
			g->p++;
		}
		g->j++;
	}
}

void	calc(t_general *g)
{
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
		if (g->f.nr * g->f.nr + g->f.ni * g->f.ni > 4)
			break ;
		g->n++;
	}
	g->f.col = 255 - 255 / g->n;
	if (g->n == g->f.iter)
		g->f.col = 0;
	g->points[g->p].color.channel[0] = g->f.col;
	g->points[g->p].color.channel[1] = g->f.col;
	g->points[g->p].color.channel[2] = g->f.col;
}
