/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   delete_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/24 16:16:07 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/26 13:20:40 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	delete_textures(t_g *g)
{
	mlx_delete_texture(&g->end_screen_t->texture);
	mlx_delete_texture(&g->death_screen_t->texture);
	mlx_delete_texture(&g->collectable->collectable_t->texture);
	del_tex_map(g->map);
	del_tex_play(g->player);
	del_tex_eny(g->enemy);
	del_tex_font(g->font);
}

void	del_tex_map(t_map *map)
{
	mlx_delete_texture(&map->open_sp_t->texture);
	mlx_delete_texture(&map->wall_texture->texture);
	mlx_delete_texture(&map->exit_texture->texture);
	mlx_delete_texture(&map->open_exit_texture->texture);
	mlx_delete_texture(&map->black_texture->texture);
	mlx_delete_texture(&map->heart_texture->texture);
}

void	del_tex_play(t_player *player)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		mlx_delete_texture(&player->player_t_u[i]->texture);
		mlx_delete_texture(&player->player_t_d[i]->texture);
		mlx_delete_texture(&player->player_t_r[i]->texture);
		mlx_delete_texture(&player->player_t_l[i]->texture);
		i++;
	}
}

void	del_tex_eny(t_enemy *enemy)
{
	int	i;

	i = 0;
	while (i <= 2)
	{
		mlx_delete_texture(&enemy->enemy_t_u[i]->texture);
		mlx_delete_texture(&enemy->enemy_t_d[i]->texture);
		mlx_delete_texture(&enemy->enemy_t_r[i]->texture);
		mlx_delete_texture(&enemy->enemy_t_l[i]->texture);
		i++;
	}
}	

void	del_tex_font(t_font *font)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_delete_texture(&font->d_t[i]->texture);
		i++;
	}
}
