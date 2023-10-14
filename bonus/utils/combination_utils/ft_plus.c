/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:17:51 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/14 05:19:01 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

ssize_t	ft_parse_plus(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == 'd' || format[i] == 'i')
		{
			line->plus = ON;
			return (i);
		}
	}
	return (OFF);
}
