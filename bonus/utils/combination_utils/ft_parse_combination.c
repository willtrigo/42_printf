/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_combination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:55 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/16 20:23:35 by dande-je         ###   ########.org.br   */
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
			return (ft_parse_hash(format, line));
		else if (*format == ' ')
			return (ft_parse_space(format, line));
		else if (*format == '+')
			return (ft_parse_plus(format, line));
		else if (*format == '-')
			return (ft_parse_minus(format, line));
		else if (*format == '0')
			return (ft_parse_zero(format, line));
		else if (*format >= '1' && *format <= '9')
			return (ft_parse_width(format, line));
		format++;
	}
	return (OFF);
}
