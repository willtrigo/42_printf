/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_combination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:55 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/15 04:33:51 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_parse_combination(const char *format, t_line *line, int i_spec)
{
	while (SPEC[i_spec])
		if (*format == SPEC[i_spec++])
			return (OFF);
	while (*format)
	{
		if (*format == '#')
		{
			line->hash = ON;
			return (JUMP);
		}
		else if (*format == ' ')
			return (ft_parse_space(format, line));
		else if (*format == '+')
			return (ft_parse_plus(format, line));
		else if (*format == '-')
			return (ft_parse_minus(format, line));
		format++;
	}
	return (OFF);
}
