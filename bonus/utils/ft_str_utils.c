/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 07:09:05 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 07:56:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

void	ft_str_insert(char *str, t_line *line)
{
	if (line->prec >= ON)
	{
		while (line->prec--)
			if (*str)
				ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
	}
	else
		while (*str)
			ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
}

int	ft_str_len(const char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}
