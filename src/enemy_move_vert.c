/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_move_vert.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 21:24:05 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/28 01:02:19 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy_vert(t_g *g)
{
	int	i;

	i = 0;
	while (i < g->count_enemyv)
	{
		g->enemy->img_count += 1;
		if (g->enemy->img_count > 12)
			g->enemy->img_count = 0;
		if (g->enemy->dir_vert == 1)
			move_enemy_down(i, g);
		if (g->enemy->dir_vert == -1)
			move_enemy_up(i, g);
		i++;
	}
}

void	move_enemy_down(int i, t_g *g)
{
	if (check_valid_move((g->enemy->enemy_imgv->instances[i].y
				/ g->map->base_height) + 1,
			g->enemy->enemy_imgv->instances[i].x
			/ g->map->base_width, g->grid))
	{
		mlx_draw_texture(g->enemy->enemy_imgv,
			&g->enemy->enemy_t_d[g->enemy->img_count / 6]->texture, 0, 0);
		g->enemy->enemy_imgv->instances[i].y += 2;
	}
	else
		g->enemy->dir_vert = -1;
}

void	move_enemy_up(int i, t_g *g)
{
	if (check_valid_move((g->enemy->enemy_imgv->instances[i].y
				/ g->map->base_height),
			g->enemy->enemy_imgv->instances[i].x
			/ g->map->base_width, g->grid))
	{
		mlx_draw_texture(g->enemy->enemy_imgv,
			&g->enemy->enemy_t_u[g->enemy->img_count / 6]->texture, 0, 0);
		g->enemy->enemy_imgv->instances[i].y -= 2;
	}
	else
		g->enemy->dir_vert = 1;
}
