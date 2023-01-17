/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:58:42 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 15:31:53 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
	{
		ft_printf("Error: ./so_long");
	}
	else
	{
		ft_printf("%s", str);
	}
	(void)error;
	exit(error);
}
