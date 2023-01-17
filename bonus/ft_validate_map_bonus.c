/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrank <lfrank@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:59:47 by lfrank            #+#    #+#             */
/*   Updated: 2023/01/11 15:37:55 by lfrank           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_validate_map(char *str_map, t_game *game)
{
	ft_validate_characters(str_map);
	ft_amount_of_characters(str_map, game);
	ft_validate_length(str_map);
	ft_validate_line_length(str_map);
}

void	ft_validate_characters(char *str_map)
{
	int	i;

	i = 0;
	while (str_map[i])
	{
		if (str_map[i] != '0' && str_map[i] != '1' && str_map[i] != 'E'
			&& str_map[i] != 'P' && str_map[i] != 'C' && str_map[i] != '\n'
			&& str_map[i] != 'X')
			ft_error_message(E_CHARS, 1);
		i++;
	}
}

void	ft_amount_of_characters(char *str_map, t_game *game)
{
	int	i;
	int	p_count;
	int	c_count;
	int	e_count;

	i = 0;
	p_count = 0;
	c_count = 0;
	e_count = 0;
	while (str_map[i++])
	{
		if (str_map[i] == 'C')
			c_count++;
		if (str_map[i] == 'E')
			e_count++;
		if (str_map[i] == 'P')
			p_count++;
	}
	if (p_count != 1 || e_count != 1 || c_count < 1)
		ft_error_message(E_CHARS, 1);
	game->c_count = c_count;
}

void	ft_validate_length(char *str_map)
{
	int	i;
	int	count_first_line;

	i = 0;
	count_first_line = 0;
	while (str_map[i] != '\n')
	{
		count_first_line++;
		i++;
	}
	if (count_first_line >= 128)
		ft_error_message(E_MAX, 1);
}

void	ft_validate_line_length(char *str_map)
{
	int	i;
	int	count_first_line;
	int	count_other_lines;

	i = 0;
	count_first_line = 0;
	count_other_lines = 0;
	while (str_map[i] != '\n')
	{
		count_first_line++;
		i++;
	}
	i++;
	while (str_map[i] != '\0')
	{
		if (str_map[i] == '\n')
		{
			if (count_other_lines != count_first_line)
				ft_error_message(E_INVALIDMAP, 1);
			count_other_lines = 0;
		}
		else
			count_other_lines++;
		i++;
	}
}
