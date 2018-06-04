/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:47:57 by vordynsk          #+#    #+#             */
/*   Updated: 2018/05/11 18:48:00 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_clearscr(t_general *gen)
{
	int		i;

	i = 0;
	while (i < gen->size_x * gen->size_y * 4)
	{
		gen->image[i] = '\0';
		i++;
	}
}

void	ft_screen_stuff(t_general *g)
{
	ft_clearscr(g);
	mlx_clear_window(g->init, g->win);
	if (g->fr_num == 1)
		calc(g, mandelbrot);
	if (g->fr_num == 2)
		calc(g, julia);
	mlx_put_image_to_window(g->init, g->win, g->img, 0, 0);
}

int		mouse_pos(int x, int y, t_general *g)
{
	g->mouse_x = x;
	g->mouse_y = y;
	if (g->fr_num == 2)
	{
		g->f.cr = -0.7 + g->mouse_x/1000;
		g->f.ci = 0.27015 + g->mouse_y/1000;
	}
	//printf("g->f.cr = %f, g->f.ci = %f, x = %d, y = %d\n", g->f.cr, g->f.ci, x, y);
	ft_screen_stuff(g);
	return (0);
}

int		ft_compare(t_general *g, char *fr_str)
{
	g->mand = ft_strnew(10);
	g->jul = ft_strnew(5);
	g->mand = ft_strcpy(g->mand, "Mandelbrot");
	g->jul = ft_strcpy(g->jul, "Julia");
	if (ft_strcmp(g->mand, fr_str) == 0)
	{	
		g->fr_num = 1;
		g->size_x = 2000;
		g->size_y = 1400;
		g->f.zoom = 0.8;
		g->f.moX = -0.7;
		g->f.moY = 0;
	}
	else if (ft_strcmp(g->jul, fr_str) == 0)
	{
		g->fr_num = 2;
		g->size_x = 1000;
		g->size_y = 1000;
		g->f.zoom = 1;
		g->f.moX = 0;
		g->f.moY = 0;
	}
	else
		return (0);
	//printf("movex = %f, movey = %f, zoom = %f\n", g->f.moX, g->f.moY, g->f.zoom);
	return (1);
}
