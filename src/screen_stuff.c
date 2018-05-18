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
	mlx_put_image_to_window(g->init, g->win, g->img, 300, 0);
}

void	ft_compare(t_general *g, char *fr_str)
{
	char	*mand;
	char	*jul;
	
	mand = ft_strnew(10);
	jul = ft_strnew(5);
	mand = ft_strcpy(mand, "Mandelbrot");
	jul = ft_strcpy(jul, "Julia");
	if (ft_strcmp(mand, fr_str) == 0)
	{	
		g->fr_num = 1;
		g->size_x = 2000;
		g->size_y = 1400;
	}
	else if (ft_strcmp(jul, fr_str) == 1)
		g->fr_num = 2;
	ft_strdel(&mand);
	ft_strdel(&jul);
}
