/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_move_hori.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 21:24:05 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/30 12:56:19 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_hori(t_g *g)
{
	int	i;

	i = 0;
	while (i < g->count_enemyh)
	{
		g->enemy->img_count += 1;
		if (g->enemy->img_count > 12)
			g->enemy->img_count = 0;
		if (g->enemy->dir_hori == 1)
			move_enemy_right(i, g);
		if (g->enemy->dir_hori == -1)
			move_enemy_left(i, g);
		i++;
	}
}

void	move_enemy_right(int i, t_g *g)
{
	if (check_valid_move(g->enemy->enemy_imgh->instances[i].y
			/ g->map->base_height, (g->enemy->enemy_imgh->instances[i].x
				/ g->map->base_width) + 1, g->grid))
	{
		mlx_draw_texture(g->enemy->enemy_imgh,
			&g->enemy->enemy_t_r[g->enemy->img_count / 6]->texture, 0, 0);
			g->enemy->enemy_imgh->instances[i].x += 2;
	}
	else
		g->enemy->dir_hori = -1;
}

void	move_enemy_left(int i, t_g *g)
{
	if (check_valid_move(g->enemy->enemy_imgh->instances[i].y
			/ g->map->base_height, (g->enemy->enemy_imgh->instances[i].x
				/ g->map->base_width), g->grid))
	{
		mlx_draw_texture(g->enemy->enemy_imgh,
			&g->enemy->enemy_t_l[g->enemy->img_count / 6]->texture, 0, 0);
			g->enemy->enemy_imgh->instances[i].x -= 2;
	}
	else
		g->enemy->dir_hori = 1;
}
