/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_img.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 09:31:33 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/27 09:29:14 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_font_heart(t_g *g)
{
	mlx_image_to_window(g->mlx, g->font->fd_img, 10,
		g->grid_height * g->map->base_height + 10);
	mlx_image_to_window(g->mlx, g->font->sd_img, 40,
		g->grid_height * g->map->base_height + 10);
	mlx_image_to_window(g->mlx, g->font->td_img, 70,
		g->grid_height * g->map->base_height + 10);
	mlx_image_to_window(g->mlx, g->map->heart_img, g->grid_width
		* g->map->base_width - 60, g->grid_height * g->map->base_height);
	mlx_image_to_window(g->mlx, g->map->heart_img, g->grid_width
		* g->map->base_width - 110, g->grid_height * g->map->base_height);
	mlx_image_to_window(g->mlx, g->map->heart_img, g->grid_width
		* g->map->base_width - 160, g->grid_height * g->map->base_height);
}

void	put_exit_collect(t_g *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->grid_height)
	{
		while (x < g->grid_width)
		{
			if (g->grid[y][x] == 'E')
			{
				put_img(g->map->open_exit_img, x, y, g);
				put_img(g->map->exit_img, x, y, g);
			}
			if (g->grid[y][x] == 'C')
				put_collectable(x, y, g);
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	put_player(t_g *g)
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
			{
				put_img(g->player->player_img, x, y, g);
				g->player->p_x = x;
				g->player->p_y = y;
			}
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

void	put_enemy(int x, int y, t_g *g)
{
	int	total_put;

	total_put = g->put_enemyh + g->put_enemyv;
	if (total_put % 2 == 0 && g->put_enemyv < g->count_enemyv)
	{
		put_img(g->enemy->enemy_imgv, x, y, g);
		g->put_enemyv++;
	}
	if (total_put % 2 != 0 && g->put_enemyh < g->count_enemyh)
	{
		put_img(g->enemy->enemy_imgh, x, y, g);
		g->put_enemyh++;
	}
	total_put--;
}

void	put_collectable(int x, int y, t_g *g)
{
	g->collectable->c_x = x;
	g->collectable->c_y = y;
	mlx_image_to_window(g->mlx, g->collectable->collectable_img,
		x * g->map->base_width + g->collectable->offset_x, y
		* g->map->base_height + g->collectable->offset_y);
	put_enemy(x, y, g);
}
