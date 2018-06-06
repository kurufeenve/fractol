/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:42:34 by vordynsk          #+#    #+#             */
/*   Updated: 2018/06/04 17:42:36 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	ft_move(t_general *g, int key)
{
	if (key == 126)
	{
		g->f.moY += 0.1;
		ft_screen_stuff(g);
	}
	else if (key == 125)
	{
		g->f.moY -= 0.1;
		ft_screen_stuff(g);
	}
	else if (key == 123)
	{
		g->f.moX -= 0.1;
		ft_screen_stuff(g);
	}
	else if (key == 124)
	{
		g->f.moX += 0.1;
		ft_screen_stuff(g);
	}
}

int		ft_zoom(int mouse_but, int x, int y, t_general *g)
{
	if (mouse_but == 5)
	{
		g->f.zoom += 0.1;
		g->f.moX += (g->mouse_x - g->size_x / 2) / (10000 * g->f.zoom);
		g->f.moY += (g->mouse_y - g->size_y / 2) / (10000 * g->f.zoom);
	}
	if (mouse_but == 4)
	{
		g->f.zoom -= 0.1;
		g->f.moX -= (g->mouse_y - g->size_x / 2) / (10000 * g->f.zoom);
		g->f.moY -= (g->mouse_y - g->size_y / 2) / (10000 * g->f.zoom);
	}
	printf("x = %d, y = %d, movex = %f, movey = %f, zoom = %f\n", x, y, (g->mouse_x - g->size_x / 2) / 1000, g->f.moY, g->f.zoom);
	ft_screen_stuff(g);
	return (0);
}
