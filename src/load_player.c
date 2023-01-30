/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_player.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 18:12:24 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/27 09:38:20 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_player(t_g *g)
{
	load_pup(g);
	load_pdown(g);
	load_pleft(g);
	load_pright(g);
	g->player->img_count = 0;
	g->player->player_img = mlx_texture_to_image
		(g->mlx, &g->player->player_t_d[0]->texture);
	g->player->life = 3;
}

void	load_pup(t_g *g)
{
	g->player->player_t_u = malloc(sizeof(xpm_t) * 3);
	if (!g->player->player_t_u)
		error_msg("ERROR\nMalloc for movement sprites", g);
	g->player->player_t_u[0] = mlx_load_xpm42
		("./images/player/link_up_1.xpm42");
	g->player->player_t_u[1] = mlx_load_xpm42
		("./images/player/link_up_2.xpm42");
	g->player->player_t_u[2] = mlx_load_xpm42
		("./images/player/link_up_3.xpm42");
}

void	load_pdown(t_g *g)
{
	g->player->player_t_d = malloc(sizeof(xpm_t) * 3);
	if (!g->player->player_t_d)
		error_msg("ERROR\nMalloc for movement sprites", g);
	g->player->player_t_d[0] = mlx_load_xpm42
		("./images/player/link_down_1.xpm42");
	g->player->player_t_d[1] = mlx_load_xpm42
		("./images/player/link_down_2.xpm42");
	g->player->player_t_d[2] = mlx_load_xpm42
		("./images/player/link_down_3.xpm42");
}

void	load_pleft(t_g *g)
{
	g->player->player_t_l = malloc(sizeof(xpm_t) * 3);
	if (!g->player->player_t_l)
		error_msg("ERROR\nMalloc for movement sprites", g);
	g->player->player_t_l[0] = mlx_load_xpm42
		("./images/player/link_left_1.xpm42");
	g->player->player_t_l[1] = mlx_load_xpm42
		("./images/player/link_left_2.xpm42");
	g->player->player_t_l[2] = mlx_load_xpm42
		("./images/player/link_left_3.xpm42");
}

void	load_pright(t_g *g)
{
	g->player->player_t_r = malloc(sizeof(xpm_t) * 3);
	if (!g->player->player_t_r)
		error_msg("ERROR\nMalloc for movement sprites", g);
	g->player->player_t_r[0] = mlx_load_xpm42
		("./images/player/link_right_1.xpm42");
	g->player->player_t_r[1] = mlx_load_xpm42
		("./images/player/link_right_2.xpm42");
	g->player->player_t_r[2] = mlx_load_xpm42
		("./images/player/link_right_3.xpm42");
}
