/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:53:59 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/09 15:28:49 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
	{
		ft_printf("Error: ./so_long");
	}
	else
	{
		write(2, "Error\n", 7);
		ft_printf("%s", str);
	}
	(void)error;
	exit(error);
}
