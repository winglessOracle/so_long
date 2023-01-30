/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 15:50:51 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/26 16:21:18 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_g *g)
{
	g->end_screen_t = mlx_load_xpm42("./images/map/end_screen.xpm42");
	g->death_screen_t = mlx_load_xpm42("./images/map/death_screen.xpm42");
	g->map->open_sp_t = mlx_load_xpm42
		("./images/map/open_space.xpm42");
	g->map->wall_texture = mlx_load_xpm42("./images/map/wall.xpm42");
	g->map->exit_texture = mlx_load_xpm42("./images/map/exit.xpm42");
	g->map->open_exit_texture = mlx_load_xpm42("./images/map/open_exit.xpm42");
	g->map->black_texture = mlx_load_xpm42("./images/map/black.xpm42");
	g->map->heart_texture = mlx_load_xpm42("./images/map/heart.xpm42");
	g->map->exit_img = mlx_texture_to_image
		(g->mlx, &g->map->exit_texture->texture);
	g->map->open_exit_img = mlx_texture_to_image
		(g->mlx, &g->map->open_exit_texture->texture);
	g->map->black_img = mlx_texture_to_image
		(g->mlx, &g->map->black_texture->texture);
	g->map->heart_img = mlx_texture_to_image
		(g->mlx, &g->map->heart_texture->texture);
	g->screen_img = mlx_new_image(g->mlx, 800, 600);
	g->map->base_height = g->map->open_sp_t->texture.height;
	g->map->base_width = g->map->open_sp_t->texture.width;
	g->map->walls_img = mlx_new_image(g->mlx, g->grid_width
			* g->map->base_width, g->grid_height * g->map->base_height);
	g->map->bg_img = mlx_new_image(g->mlx, g->grid_width
			* g->map->base_width, (g->grid_height + 1) * g->map->base_height);
}

void	load_collectable(t_g *g)
{
	g->collectable->offset_x = 5;
	g->collectable->offset_y = 5;
	g->collectable->c_x = 0;
	g->collectable->c_y = 0;
	g->collectable->collectable_t = mlx_load_xpm42
		("./images/map/collectable1.xpm42");
	g->collectable->collectable_img = mlx_texture_to_image(g->mlx,
			&g->collectable->collectable_t->texture);
}

void	load_font(t_g *g)
{
	g->font->offset_x = 0;
	g->font->offset_y = 12;
	g->font->d_t[0] = mlx_load_xpm42("./font/0.xpm42");
	g->font->d_t[1] = mlx_load_xpm42("./font/1.xpm42");
	g->font->d_t[2] = mlx_load_xpm42("./font/2.xpm42");
	g->font->d_t[3] = mlx_load_xpm42("./font/3.xpm42");
	g->font->d_t[4] = mlx_load_xpm42("./font/4.xpm42");
	g->font->d_t[5] = mlx_load_xpm42("./font/5.xpm42");
	g->font->d_t[6] = mlx_load_xpm42("./font/6.xpm42");
	g->font->d_t[7] = mlx_load_xpm42("./font/7.xpm42");
	g->font->d_t[8] = mlx_load_xpm42("./font/8.xpm42");
	g->font->d_t[9] = mlx_load_xpm42("./font/9.xpm42");
	g->font->fd_img = mlx_texture_to_image
		(g->mlx, &g->font->d_t[0]->texture);
	g->font->sd_img = mlx_texture_to_image
		(g->mlx, &g->font->d_t[0]->texture);
	g->font->td_img = mlx_texture_to_image
		(g->mlx, &g->font->d_t[0]->texture);
}
