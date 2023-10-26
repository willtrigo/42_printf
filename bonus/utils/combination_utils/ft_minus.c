/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:27:37 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:27:04 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static int	ft_minus_0(const char *format, t_line *line);
static int	ft_get_minus(const char *format, t_line *line, int i);

ssize_t	ft_parse_minus(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	line->minus = ON;
	if (*format == '0' && format[2] == '%')
		return (2 + ft_parse_zero((format + 1), line));
	if (*format == '-')
		format++;
	if (ft_minus_0(format, line) == ON)
		return (2);
	while (format[++i])
	{
		if (ft_check_spec(format, i) == ON)
			return (i + 1);
		if (format[i] == '.')
			return (i + 1 + ft_parse_precision((format + i), line));
		else if (format[i] >= '1' && format[i] <= '9')
		{
			i = ft_get_minus(format, line, i);
		}
	}
	return (i + 1);
}

static int	ft_minus_0(const char *format, t_line *line)
{
	if (format[0] == '0')
	{
		line->minus = OFF;
		return (ON);
	}
	return (OFF);
}

static int	ft_get_minus(const char *format, t_line *line, int i)
{
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	line->minus = ft_get_combination_nbr(format, DEFAULT_INIT,
			i--, DEFAULT_INIT);
	return (i);
}
