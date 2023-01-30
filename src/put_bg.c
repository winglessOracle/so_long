/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_bg.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 14:28:57 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/27 09:21:52 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	put_bg(t_g *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < g->grid_height)
	{
		while (x < g->grid_width)
		{
			mlx_draw_texture(g->map->bg_img, &g->map->open_sp_t->texture,
				x * g->map->base_width, y * g->map->base_height);
			if (g->grid[y][x] == '1')
				mlx_draw_texture(g->map->walls_img,
					&g->map->wall_texture->texture, x * g->map->base_width,
					y * g->map->base_height);
			mlx_put_pixel(g->map->bg_img, x, y, 000);
			if (y == g->grid_height - 1)
				black_line(x, y, g);
			x += 1;
		}
		x = 0;
		y += 1;
	}
	mlx_image_to_window(g->mlx, g->map->bg_img, 0, 0);
	mlx_image_to_window(g->mlx, g->map->walls_img, 0, 0);
}

void	black_line(int x, int y, t_g *g)
{
	mlx_draw_texture(g->map->bg_img, &g->map->black_texture->texture,
		x * g->map->base_width, (y + 1) * g->map->base_height);
}
