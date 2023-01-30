/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flood_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 13:13:31 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/27 09:35:55 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_check(char *input_file, t_g *g)
{
	t_flood		*flood;

	flood = (t_flood *)malloc(sizeof(t_flood));
	if (!flood)
		error_msg_pre_load("ERROR\nFailed floodcheck malloc\n", g);
	init_flood(input_file, flood);
	find_pc(flood);
	flood_fill(flood->p_x, flood->p_y, flood, g);
	if (!(flood->count_collect == 0 && flood->exit_found == true))
	{
		free_flood(flood);
		error_msg_pre_load("ERROR\nMap does not have a valid solution\n", g);
	}
	free_flood(flood);
}

void	flood_fill(int x, int y, t_flood *flood, t_g *g)
{
	if (x < 0 || x > flood->cols - 1 || y < 0 || y > flood->rows - 1)
	{
		free_flood(flood);
		error_msg_pre_load("ERROR\nMap is not enclosed by walls.\n", g);
	}
	if (flood->map[y][x] == '1')
		return ;
	if (flood->map[y][x] != 'f')
	{
		if (flood->map[y][x] == 'C')
			flood->count_collect -= 1;
		if (flood->map[y][x] == 'E')
			flood->exit_found = true;
		flood->map[y][x] = 'f';
		flood_fill(x - 1, y, flood, g);
		flood_fill(x, y + 1, flood, g);
		flood_fill(x + 1, y, flood, g);
		flood_fill(x, y - 1, flood, g);
	}
}

void	init_flood(char *input_file, t_flood *flood)
{
	flood->map = generate_map_flood(input_file);
	flood->rows = 0;
	flood->cols = 0;
	flood->count_collect = 0;
	flood->p_x = 0;
	flood->p_y = 0;
	flood->exit_found = false;
	while (flood->map[flood->rows])
		flood->rows += 1;
	while (flood->map[0][flood->cols])
		flood->cols += 1;
}

void	find_pc(t_flood *flood)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < flood->rows)
	{
		while (x < flood->cols)
		{
			if (flood->map[y][x] == 'C')
				flood->count_collect += 1;
			if (flood->map[y][x] == 'P')
			{
				flood->p_x = x;
				flood->p_y = y;
			}
			x += 1;
		}
		x = 0;
		y += 1;
	}
}

char	**generate_map_flood(char *input_file)
{
	int		fd;
	char	*line;
	char	*joined_lines;
	char	**ret;

	line = "";
	joined_lines = ft_strdup("");
	fd = open (input_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin_free_s1(joined_lines, line);
		free (line);
	}
	free (line);
	close(fd);
	ret = ft_split(joined_lines, '\n');
	free (joined_lines);
	return (ret);
}
