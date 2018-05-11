/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vordynsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:29:59 by vordynsk          #+#    #+#             */
/*   Updated: 2018/05/03 16:30:02 by vordynsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		main(int argc, char **argv)
{
	t_general	g;

	// if (argc != 2)
	// {
	// 	ft_putstr("map error\n");
	// 	return (0);
	// }
	g.size_x = 1000;
	g.size_y = 1000;
	map(&g);
	g.p = 0;
	while (g.p < g.n)
	{
		printf("index = %d, x = %f, y = %f, z = %f, color = %x\n", g.p, g.points[g.p].x, g.points[g.p].y, g.points[g.p].z, g.points[g.p].color.color);
		g.p++;
	}
	if ((g.init = mlx_init()) == NULL ||
		(g.win = mlx_new_window(g.init,
		g.size_x, g.size_y, "test")) == NULL || (g.img =
		mlx_new_image(g.init, g.size_x, g.size_y)) == NULL ||
		(g.image = mlx_get_data_addr(g.img, &g.bpp, &g.val,
		&g.ed)) == NULL)
		return (0);
	mlx_hook(g.win, 2, 5, key_hook, &g);
	mlx_hook(g.win, 17, 1L << 17, exit_x, NULL);
	mlx_loop(g.init);
    return (0);
}

int		exit_x(void)
{
	system("leaks fractol");
	exit(1);
}

void	put_pixel(t_general *g, int x, int y, t_color color)
{
	g->image[y * g->val + 4 * x] = color.channel[0];
	g->image[y * g->val + 4 * x + 1] = color.channel[1];
	g->image[y * g->val + 4 * x + 2] = color.channel[2];
}

int		key_hook(int key, void *ptr)
{
	t_general	*g;

	g = ptr;
	if (key == 53)
	{
		system("leaks fractol");
		exit(0);
	}
	return (0);
}

void	map(t_general *g)
{
	g->i = 0;
	g->p = 0;
	g->color.color = 0x000000;
	g->n = g->size_x * g->size_y;
	g->points = (t_point *)malloc(sizeof(t_point) * g->n);
	while (g->i < g->size_y)
	{
		g->j = 0;
		while (g->j < g->size_x && g->p < g->n)
		{
			g->points[g->p].x = g->j;
			g->points[g->p].y = g->i;
			g->points[g->p].z = 0;
			g->points[g->p].color.color = g->color.color;
			g->p++;
			g->j++;
		}
		g->i++;
	}
	g->i = 0;
	g->j = 0;
	g->p = 0;
}
