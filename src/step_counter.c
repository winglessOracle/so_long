/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   step_counter.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 15:01:09 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/30 12:54:34 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_step_img(t_g *g)
{
	char	*steps;
	int		i;

	steps = ft_itoa(g->count_steps);
	i = 0;
	while (steps[i])
		i++;
	if (i == 3)
	{
		count_three_dig(steps, g);
		free(steps);
	}
	else if (i == 2)
	{
		count_two_dig(steps, g);
		free(steps);
	}
	else if (i == 1)
	{	
		count_one_dig(steps, g);
		free(steps);
	}
	else
		g->count_steps = 1;
}

void	count_one_dig(char *steps, t_g *g)
{
	mlx_draw_texture(g->font->td_img,
		&g->font->d_t[((int)steps[0] - '0')]->texture, 0, 0);
}

void	count_two_dig(char *steps, t_g *g)
{
	mlx_draw_texture(g->font->sd_img,
		&g->font->d_t[((int)steps[0] - '0')]->texture, 0, 0);
	mlx_draw_texture(g->font->td_img,
		&g->font->d_t[((int)steps[1] - '0')]->texture, 0, 0);
}

void	count_three_dig(char *steps, t_g *g)
{
	mlx_draw_texture(g->font->fd_img,
		&g->font->d_t[((int)steps[0] - '0')]->texture, 0, 0);
	mlx_draw_texture(g->font->sd_img,
		&g->font->d_t[((int)steps[1] - '0')]->texture, 0, 0);
	mlx_draw_texture(g->font->td_img,
		&g->font->d_t[((int)steps[2] - '0')]->texture, 0, 0);
}
