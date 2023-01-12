/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:57:15 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 11:25:38 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_message(t_game *game)
{
	if (game->state == STATE_SUCCESS)
	{
		ft_printf("\n\n CONGRATULATIONS!!!");
		ft_printf("You completed the game in %d moves!\n", game->move_count);
	}
	else if (game->state == STATE_CLOSING)
		ft_printf("\n\n Next time, we should get these nuts!\n");
	else if (game->state == STATE_GAMEOVER)
		ft_printf("Oh no! Next time, try to avoid them.\n");
}
