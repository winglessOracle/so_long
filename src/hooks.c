/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 09:01:21 by Carlo Wesse   #+#    #+#                 */
/*   Updated: 2023/01/27 15:40:27 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_g	*g;

	g = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_exit("You left the game\n", g);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		pmove_up(g);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		pmove_down(g);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		pmove_left(g);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		pmove_right(g);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		restart_map(g->current_map, g);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		restart_map("levels/level_1.ber", g);
}

void	loophook(void *param)
{
	t_g	*g;

	g = param;
	move_enemy_hori(g);
	move_enemy_vert(g);
	check_enemy_attack(g);
}

void	closehook(void *param)
{
	t_g	*g;

	g = param;
	clean_exit("\nYou left the game.\n", g);
}

void	set_hooks(t_g *g)
{
	mlx_key_hook(g->mlx, keyhook, g);
	mlx_close_hook(g->mlx, closehook, g);
	mlx_loop_hook(g->mlx, loophook, g);
}
