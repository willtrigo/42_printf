/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:23 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:26:07 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

ssize_t	ft_parse_zero(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	line->zero = ON;
	while (format[++i])
	{
		if (ft_check_spec(format, i) == ON)
			return (i);
		if (format[i] >= '1' && format[i] <= '9')
		{
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			line->zero = ft_get_combination_nbr(format, DEFAULT_INIT,
					i--, DEFAULT_INIT);
		}
		else if (format[i] == '.')
			return (i + ft_parse_precision((format + i), line));
		else if (format[i] == '-')
			return (i + ft_parse_minus((format + i), line));
	}
	return (i + 1);
}
