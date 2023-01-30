/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:45:40 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/27 09:40:19 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_grid(t_g *g)
{
	while (g->grid[g->grid_height])
		g->grid_height += 1;
	while (g->grid[0][g->grid_width])
		g->grid_width += 1;
	if (g->grid_height > 25 || g->grid_width > 50)
		error_msg_pre_load("ERROR\nMap too big. Max map size is 50 x 25\n", g);
	check_grid_shape(g);
	check_grid_symbols(g);
	set_enemy_counter(g);
	return (0);
}

void	check_grid_symbols(t_g *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->grid_height)
	{
		while (x < g->grid_width)
		{
			if (g->grid[y][x] == 'P')
				g->count_player += 1;
			if (g->grid[y][x] == 'E')
				g->count_exit += 1;
			if (g->grid[y][x] == 'C')
				g->count_collect += 1;
			if (!(ft_strchr(g->allowed_symbols, (int)g->grid[y][x])))
				error_msg_pre_load("ERROR\nMap contains unkown symbols.\n", g);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	if (g->count_collect < 1 || g->count_player != 1 || g->count_exit != 1)
		error_msg_pre_load("ERROR\nMap does not meet requirements.\n", g);
}

void	check_grid_shape(t_g *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->grid_height)
	{
		while (g->grid[y][x])
			x += 1;
		if (x != g->grid_width)
			error_msg_pre_load("ERROR\nMap is not rectangular\n", g);
		x = 0;
		y += 1;
	}
}

void	set_enemy_counter(t_g *g)
{
	if (g->count_collect > 2 && g->grid_height * g->grid_width > 100)
	{
		g->count_enemyh = g->count_collect / 2 - 1;
		g->count_enemyv = g->count_collect / 2 - 1;
	}
}
