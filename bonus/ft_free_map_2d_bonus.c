/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D_copy_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:28:35 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 16:32:00 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
