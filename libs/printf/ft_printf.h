/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:08:32 by lfrank            #+#    #+#             */
/*   Updated: 2022/11/10 20:12:30 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define B_10 "0123456789"
# define B_16MIN "0123456789abcdef"
# define B_16MAJ "0123456789ABCDEF"

# include <stdarg.h>
# include <unistd.h>

int	ft_printnbr(int n);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_digitlen(int nb, char c);
int	ft_printhex(unsigned long nb, int b_is_X);
int	ft_printf(const char *format, ...);
int	ft_printpointer(size_t ptr);
int	ft_printnbr_u(unsigned int nb);

#endif
