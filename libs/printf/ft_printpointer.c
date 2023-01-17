/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:23:29 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/10 20:12:32 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(size_t ptr)
{
	int	len;

	len = ft_digitlen(0, 'p');
	len += ft_printstr("0x");
	len += ft_printhex((unsigned long)ptr, 0);
	return (len - 1);
}
