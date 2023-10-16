/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:19:09 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/15 16:03:31 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static int	ft_get_width(const char *format, ssize_t format_init,
				ssize_t format_end, int nbr);

ssize_t	ft_parse_width(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X')
		{
			line->width = ft_get_width(format, DEFAULT_INIT, i, DEFAULT_INIT);
			return (i);
		}
	}
	return (OFF);
}

static int	ft_get_width(const char *format, ssize_t format_init,
		ssize_t format_end, int nbr)
{
	while (format_init++ < format_end)
		nbr = (nbr * 10) + (*(format++) - '0');
	return (nbr);
}
