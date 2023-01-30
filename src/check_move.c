/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_move.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:36:21 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/30 17:48:28 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_new_ppos(t_g *g)
{
	if ((g->grid[g->player->p_y][g->player->p_x]) == 'C')
		remove_collectable(g);
	if ((g->grid[g->player->p_y][g->player->p_x]) == 'E' &&
			g->exit_open)
		next_level(g);
	g->count_steps += 1;
}

void	check_enemy_attack(t_g *g)
{
	int	i;

	i = 0;
	if (mlx_get_time() - g->time_attack > 0.8)
	{
		while (i < g->count_enemyh)
		{
			if ((g->enemy->enemy_imgh->instances[i].y)
				/ g->map->base_height == g->player->p_y
				&& (g->enemy->enemy_imgh->instances[i].x)
				/ g->map->base_width == g->player->p_x)
				remove_heart(g);
			i++;
		}
		i = 0;
		while (i < g->count_enemyv)
		{
			if ((g->enemy->enemy_imgv->instances[i].y)
				/ g->map->base_height == g->player->p_y
				&& (g->enemy->enemy_imgv->instances[i].x)
				/ g->map->base_width == g->player->p_x)
				remove_heart(g);
			i++;
		}
	}
}

void	remove_collectable(t_g *g)
{
	int	i;

	i = 0;
	while (i < g->count_collect)
	{
		if (g->collectable->collectable_img->instances[i].x
			- g->collectable->offset_x == g->player->player_img->instances[0].x
			&& g->collectable->collectable_img->instances[i].y
			- g->collectable->offset_y == g->player->player_img->instances[0].y)
			g->collectable->collectable_img->instances[i].enabled = 0;
		i++;
	}
	g->grid[g->player->p_y][g->player->p_x] = '0';
	g->count_to_exit += 1;
	if (g->count_to_exit == g->count_collect)
	{
		g->exit_open = true;
		mlx_delete_image(g->mlx, g->map->exit_img);
	}
}

void	remove_heart(t_g *g)
{
	g->map->heart_img->instances[g->player->life - 1].enabled = 0;
	g->player->life -= 1;
	if (g->player->life == 0)
		death(g);
	else
	{
		g->time_attack = mlx_get_time();
		mlx_put_string(g->mlx, "AUW!", g->player->player_img->instances[0].x, g->player->player_img->instances[0].y);
	}
}

bool	check_valid_move(int y, int x, char **grid)
{
	if (grid[y][x] == '0' || grid[y][x] == 'C' || grid[y][x] == 'E' ||
		grid[y][x] == 'P')
		return (true);
	else
		return (false);
}
