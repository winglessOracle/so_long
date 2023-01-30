/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 08:30:30 by Carlo Wesse   #+#    #+#                 */
/*   Updated: 2023/01/28 16:25:14 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_new_g(char *input_file)
{
	t_g		*g;

	g = (t_g *)malloc(sizeof(t_g));
	if (!g)
	{
		ft_printf("ERROR\nFailed malloc for t_g\n");
		exit(EXIT_FAILURE);
	}
	g->current_map = input_file;
	if (malloc_structs(g) == -1)
		error_msg_pre_load("ERROR\n Failed malloc structs.\n", g);
	init_g(g);
	g->grid = generate_map(input_file, g);
	check_grid(g);
	g->mlx = mlx_init(g->grid_width, g->grid_height, "So long!", false);
	flood_check(input_file, g);
	if (!g->mlx)
		error_msg_pre_load("ERROR\nInitializing XML\n", g);
	load_data(g);
	mlx_set_window_size(g->mlx, g->grid_width * g->map->base_width,
		g->grid_height * g->map->base_height + 50);
	mlx_set_window_pos(g->mlx, 300, 200);
	build_images(g);
	set_hooks(g);
	mlx_loop(g->mlx);
}

void	init_g(t_g *g)
{
	g->grid_width = 0;
	g->grid_height = 0;
	g->count_steps = 0;
	g->count_collect = 0;
	g->count_to_exit = 0;
	g->count_exit = 0;
	g->count_player = 0;
	g->count_level = 1;
	g->last_level = 2;
	g->count_enemyh = 0;
	g->count_enemyv = 0;
	g->put_enemyh = 0;
	g->put_enemyv = 0;
	g->time_attack = 0;
	g->allowed_symbols = "PEC0123";
	g->exit_open = false;
	g->at_exit = false;
}

void	load_data(t_g *g)
{
	load_map(g);
	load_font(g);
	load_enemy(g);
	load_collectable(g);
	load_player(g);
}

void	build_images(t_g *g)
{
	put_bg(g);
	put_font_heart(g);
	put_exit_collect(g);
	put_player(g);
}

int	malloc_structs(t_g *g)
{
	g->map = (t_map *)malloc(sizeof(t_map));
	if (!g->map)
		return (-1);
	g->font = (t_font *)malloc(sizeof(t_font));
	if (!g->font)
		return (-1);
	g->player = (t_player *)malloc(sizeof(t_player));
	if (!g->player)
		return (-1);
	g->enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!g->enemy)
		return (-1);
	g->collectable = (t_collectable *)malloc(sizeof(t_collectable));
	if (!g->collectable)
		return (-1);
	g->font->d_t = (xpm_t **)malloc(sizeof(xpm_t) * 10);
	if (!g->font->d_t)
		return (-1);
	return (1);
}
