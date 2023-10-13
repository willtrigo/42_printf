/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_combination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:55 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/13 19:28:59 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf_bonus.h"

size_t	ft_parse_combination(const char *format, t_line *line)
{
	const char	next_chr = *format;

	if (next_chr == 'c' || next_chr == 's' || next_chr == 'p'\
		|| next_chr == 'd' || next_chr == 'i' || next_chr == 'x'\
		|| next_chr == 'X' || next_chr == '%')
		return (OFF);
	while (*format)
	{
		if (*format == '#')
		{
			line->hash = ON;
			return (JUMP);
		}
		else if (*format == ' ')
		{

		}
		format++;
	}
	return (OFF);
}
