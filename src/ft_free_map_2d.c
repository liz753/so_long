/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:56:57 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 14:59:26 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_2d(char **map_2d)
{
	int	i;

	i = 0;
	if (map_2d == NULL)
		return ;
	while (map_2d[i])
	{
		free(map_2d[i]);
		i++;
	}
	free(map_2d);
	map_2d = NULL;
}
