/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.42.fr>                  +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 08:46:34 by Carlo Wesse   #+#    #+#                 */
/*   Updated: 2023/01/27 09:39:21 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extention(const char *file, const char *extention)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
		i++;
	while (extention[j])
		j++;
	while (j > -1)
	{
		if (file[i--] != extention[j--])
			return (1);
	}
	return (0);
}

void	ft_check_params(int argc, char *argv)
{
	if (argc != 2)
	{
		ft_printf("ERROR\nInvalid arguments. Please use one map argument\n");
		exit(EXIT_FAILURE);
	}
	if (ft_check_extention(argv, ".ber"))
	{
		ft_printf("ERROR\nInvalid file format. Please use a .ber file\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	free(arr);
	arr = 0;
}

void	free_flood(t_flood *flood)
{
	ft_free_array(flood->map);
	ft_free(flood);
}
