/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 22:17:19 by Carlo Wesse   #+#    #+#                 */
/*   Updated: 2023/01/26 13:02:52 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_g(t_g *g)
{
	mlx_draw_texture(g->screen_img, &g->end_screen_t->texture, 0, 0);
	mlx_set_window_size(g->mlx, 800, 600);
	mlx_image_to_window(g->mlx, g->screen_img, 0, 0);
}

void	death(t_g *g)
{
	mlx_draw_texture(g->screen_img, &g->death_screen_t->texture, 0, 0);
	mlx_set_window_size(g->mlx, 800, 600);
	mlx_image_to_window(g->mlx, g->screen_img, 0, 0);
}

void	next_level(t_g *g)
{
	static char	*levels[] = {"levels/level_1.ber",
		"levels/level_2.ber", "levels/level_3.ber"};
	char		*next_map;
	int			i;

	i = 0;
	while (i < 3)
	{
		if (ft_findchr(g->current_map, (char)i + '0'))
		{
			next_map = levels[i];
			restart_map(next_map, g);
		}
		i += 1;
	}
	end_g(g);
}

void	restart_map(char *map, t_g *g)
{
	delete_textures(g);
	mlx_terminate(g->mlx);
	init_new_g(map);
}
