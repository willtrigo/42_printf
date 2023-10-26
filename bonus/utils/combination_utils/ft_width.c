/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:19:09 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:24:09 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

ssize_t	ft_parse_width(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	line->width = ON;
	if (*format == '%')
		return (2);
	while (format[++i])
	{
		if (ft_check_spec(format, i) == ON)
			return (i);
		if (format[i] == '.')
			return (i + ft_parse_precision((format + i), line));
		else if (format[i] == '-')
			return (i + ft_parse_minus((format + i), line));
		else if (format[i] >= '1' && format[i] <= '9')
		{
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			line->width = ft_get_combination_nbr(format, DEFAULT_INIT,
					i--, DEFAULT_INIT);
		}
	}
	return (i + 1);
}

int	ft_get_width(const char *format, ssize_t format_init,
		ssize_t format_end, int nbr)
{
	while (format_init++ < format_end)
		nbr = (nbr * 10) + (*(format++) - '0');
	return (nbr);
}

t_lli	ft_get_width_int_len(t_lli nbr)
{
	t_lli	nbr_i;

	nbr_i = 0;
	if (nbr <= 0)
	{
		nbr_i++;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr_i++;
		nbr /= 10;
	}
	return (nbr_i);
}
