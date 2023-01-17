/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:58:29 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/02 14:54:41 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The putchar_fd() function outputs the character 'c' to 
the given file descriptor. */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
