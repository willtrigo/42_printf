/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:15:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/19 00:53:15 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

ssize_t	ft_parse_precision(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	while (format[++i])
	{
		line->prec = ON;
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X')
			return (i);
		if (format[i] >= '1' && format[i] <= '9')
		{
			line->prec = ft_parse_width((format + i), line);
			return (i + ft_parse_width((format + i), line));
		}
	}
	return (OFF);
}
