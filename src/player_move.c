/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_move.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 03:05:06 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/23 17:01:17 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pmove_up(t_g *g)
{
	if (check_valid_move(g->player->p_y - 1, g->player->p_x, g->grid))
	{
		g->player->img_count += 1;
		if (g->player->img_count > 2)
			g->player->img_count = 0;
		g->player->player_img->instances[0].y -= g->map->base_height;
		g->player->p_y = g->player->player_img->instances[0].y
			/ g->map->base_height;
		mlx_draw_texture(g->player->player_img,
			&g->player->player_t_u[g->player->img_count]->texture, 0, 0);
		add_step_img(g);
		check_new_ppos(g);
	}
}

void	pmove_down(t_g *g)
{
	if (check_valid_move(g->player->p_y + 1, g->player->p_x, g->grid))
	{
		g->player->img_count += 1;
		if (g->player->img_count > 2)
			g->player->img_count = 0;
		g->player->player_img->instances[0].y += g->map->base_height;
		g->player->p_y = g->player->player_img->instances[0].y
			/ g->map->base_height;
		mlx_draw_texture(g->player->player_img,
			&g->player->player_t_d[g->player->img_count]->texture, 0, 0);
		add_step_img(g);
		check_new_ppos(g);
	}
}

void	pmove_left(t_g *g)
{
	if (check_valid_move(g->player->p_y, g->player->p_x - 1, g->grid))
	{
		g->player->img_count += 1;
		if (g->player->img_count > 2)
			g->player->img_count = 0;
		g->player->player_img->instances[0].x -= g->map->base_width;
		g->player->p_x = g->player->player_img->instances[0].x
			/ g->map->base_width;
		mlx_draw_texture(g->player->player_img,
			&g->player->player_t_l[g->player->img_count]->texture, 0, 0);
		add_step_img(g);
		check_new_ppos(g);
	}
}

void	pmove_right(t_g *g)
{
	if (check_valid_move(g->player->p_y, g->player->p_x + 1, g->grid))
	{
		g->player->img_count += 1;
		if (g->player->img_count > 2)
			g->player->img_count = 0;
		g->player->player_img->instances[0].x += g->map->base_width;
		g->player->p_x = g->player->player_img->instances[0].x
			/ g->map->base_width;
		mlx_draw_texture(g->player->player_img,
			&g->player->player_t_r[g->player->img_count]->texture, 0, 0);
		add_step_img(g);
		check_new_ppos(g);
	}
}
