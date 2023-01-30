/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: carlo <carlo@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 09:45:25 by carlo         #+#    #+#                 */
/*   Updated: 2023/01/23 15:48:53 by cwesseli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_free(void *param)
{
	if (param)
		free (param);
	param = 0;
	return (0);
}
