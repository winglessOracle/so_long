/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 16:19:17 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/28 00:51:05 by carlo         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**generate_map(char *input_file, t_g *g)
{
	int		fd;
	char	*line;
	char	*joined_lines;
	char	**ret;

	line = "";
	joined_lines = ft_strdup("");
	fd = open (input_file, O_RDONLY);
	if (fd < 0)
		error_msg_mapgen1("ERROR\nFile not found\n", g);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin_free_s1(joined_lines, line);
		free (line);
	}
	close(fd);
	if (joined_lines[0] == '\0' || joined_lines[0] == '\n')
		error_msg_mapgen("ERROR\nEmpty map\n", line, joined_lines, g);
	free (line);
	ret = ft_split(joined_lines, '\n');
	free (joined_lines);
	return (ret);
}

void	free_all(t_g *g)
{
	ft_free(g->player->player_t_d);
	ft_free(g->player->player_t_u);
	ft_free(g->player->player_t_l);
	ft_free(g->player->player_t_r);
	ft_free(g->enemy->enemy_t_d);
	ft_free(g->enemy->enemy_t_u);
	ft_free(g->enemy->enemy_t_l);
	ft_free(g->enemy->enemy_t_r);
	ft_free(g->font->d_t);
	ft_free(g->player);
	ft_free(g->enemy);
	ft_free(g->collectable);
	ft_free(g->font);
	ft_free(g->map);
	ft_free_array(g->grid);
	ft_free(g);
}

void	put_img(mlx_image_t *img, int x, int y, t_g *g)
{
	mlx_image_to_window(g->mlx, img, x
		* g->map->base_width, y * g->map->base_height);
}
