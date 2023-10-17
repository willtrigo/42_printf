/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:23 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/16 20:50:07 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

ssize_t	ft_parse_zero(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	while (format[++i])
	{
		line->zero = ON;
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X')
			return (i);
		if (format[i] >= '1' && format[i] <= '9')
		{
			line->zero = ft_parse_width((format + i), line);
			return (i + ft_parse_width((format + i), line));
		}
	}
	return (OFF);
}
