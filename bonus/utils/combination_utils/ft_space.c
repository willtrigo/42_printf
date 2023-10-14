/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:12:34 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/14 05:13:27 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

ssize_t	ft_parse_space(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' || format[i] == 'd'
			|| format[i] == 'i' || format[i] == 's')
		{
			line->space = ON;
			return (i);
		}
	}
	return (OFF);
}
