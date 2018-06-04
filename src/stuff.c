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
