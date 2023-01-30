/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cwesseli <cwesseli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 12:59:31 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/27 15:13:52 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_msg_mapgen1(char *msg, t_g *g)
{
	ft_printf(msg);
	ft_free(g->font->d_t);
	ft_free(g->player);
	ft_free(g->enemy);
	ft_free(g->collectable);
	ft_free(g->font);
	ft_free(g->map);
	ft_free(g);
	exit(EXIT_FAILURE);
}

void	error_msg_mapgen(char *msg, char *line, char *joinedlines, t_g *g)
{
	ft_printf(msg);
	ft_free (line);
	ft_free (joinedlines);
	ft_free(g->font->d_t);
	ft_free(g->player);
	ft_free(g->enemy);
	ft_free(g->collectable);
	ft_free(g->font);
	ft_free(g->map);
	ft_free(g);
	exit(EXIT_FAILURE);
}

void	error_msg_pre_load(char *msg, t_g *g)
{
	ft_printf(msg);
	ft_free(g->font->d_t);
	ft_free(g->player);
	ft_free(g->enemy);
	ft_free(g->collectable);
	ft_free(g->font);
	ft_free(g->map);
	ft_free_array(g->grid);
	ft_free(g);
	exit(EXIT_FAILURE);
}

void	error_msg(char *msg, t_g *g)
{
	ft_printf(msg);
	mlx_terminate(g->mlx);
	delete_textures(g);
	free_all(g);
	exit(EXIT_FAILURE);
}

void	clean_exit(char *msg, t_g *g)
{
	ft_printf(msg);
	mlx_terminate(g->mlx);
	delete_textures(g);
	free_all(g);
	exit(EXIT_SUCCESS);
}
