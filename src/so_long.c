/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 13:27:49 by cwesseli      #+#    #+#                 */
/*   Updated: 2023/01/27 09:49:37 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	ft_check_params(argc, argv[1]);
	init_new_g(argv[1]);
	return (EXIT_SUCCESS);
}
