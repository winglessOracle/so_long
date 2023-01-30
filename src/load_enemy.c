/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_enemy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 18:12:24 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/27 09:37:48 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_enemy(t_g *g)
{
	load_eup(g);
	load_edown(g);
	load_eleft(g);
	load_eright(g);
	g->enemy->img_count = 0;
	g->enemy->enemy_imgh = mlx_texture_to_image
		(g->mlx, &g->enemy->enemy_t_r[0]->texture);
	g->enemy->enemy_imgv = mlx_texture_to_image
		(g->mlx, &g->enemy->enemy_t_d[0]->texture);
	g->enemy->dir_hori = 1;
	g->enemy->dir_vert = 1;
}

void	load_eup(t_g *g)
{
	g->enemy->enemy_t_u = malloc(sizeof(xpm_t) * 1);
	if (!g->enemy->enemy_t_u)
		error_msg("ERROR\nMalloc for enemy movement sprites", g);
	g->enemy->enemy_t_u[0] = mlx_load_xpm42
		("./images/enemy/enemy_up_1.xpm42");
	g->enemy->enemy_t_u[1] = mlx_load_xpm42
		("./images/enemy/enemy_up_2.xpm42");
	g->enemy->enemy_t_u[2] = mlx_load_xpm42
		("./images/enemy/enemy_up_3.xpm42");
}

void	load_edown(t_g *g)
{
	g->enemy->enemy_t_d = malloc(sizeof(xpm_t) * 1);
	if (!g->enemy->enemy_t_d)
		error_msg("ERROR\nMalloc for enemy movement sprites", g);
	g->enemy->enemy_t_d[0] = mlx_load_xpm42
		("./images/enemy/enemy_down_1.xpm42");
	g->enemy->enemy_t_d[1] = mlx_load_xpm42
		("./images/enemy/enemy_down_2.xpm42");
	g->enemy->enemy_t_d[2] = mlx_load_xpm42
		("./images/enemy/enemy_down_3.xpm42");
}

void	load_eleft(t_g *g)
{
	g->enemy->enemy_t_l = malloc(sizeof(xpm_t) * 1);
	if (!g->enemy->enemy_t_l)
		error_msg("ERROR\nMalloc for enemy movement sprites", g);
	g->enemy->enemy_t_l[0] = mlx_load_xpm42
		("./images/enemy/enemy_left_1.xpm42");
	g->enemy->enemy_t_l[1] = mlx_load_xpm42
		("./images/enemy/enemy_left_2.xpm42");
	g->enemy->enemy_t_l[2] = mlx_load_xpm42
		("./images/enemy/enemy_left_3.xpm42");
}

void	load_eright(t_g *g)
{
	g->enemy->enemy_t_r = malloc(sizeof(xpm_t) * 1);
	if (!g->enemy->enemy_t_r)
		error_msg("ERROR\nMalloc for enemy movement sprites", g);
	g->enemy->enemy_t_r[0] = mlx_load_xpm42
		("./images/enemy/enemy_right_1.xpm42");
	g->enemy->enemy_t_r[1] = mlx_load_xpm42
		("./images/enemy/enemy_right_2.xpm42");
	g->enemy->enemy_t_r[2] = mlx_load_xpm42
		("./images/enemy/enemy_right_3.xpm42");
}
