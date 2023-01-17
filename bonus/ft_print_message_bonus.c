/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_message_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:56 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 11:28:07 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_print_message(t_game *game)
{
	if (game->state == STATE_SUCCESS)
	{
		ft_printf("\n\nCONGRATULATIONS!!!");
		ft_printf("You completed the game in %d moves!\n", game->move_count);
	}
	else if (game->state == STATE_CLOSING && game->gameover == FALSE)
		ft_printf("\n\nNext time, we should get these nuts!\n");
	else if (game->state == STATE_GAMEOVER)
		ft_printf("Oh no! Next time, try to avoid them.\n");
}
