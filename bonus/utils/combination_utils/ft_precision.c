/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:15:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:38:59 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static int	ft_precision_str(const char *format, t_line *line);
static int	ft_get_precision(const char *format, t_line *line, int i);

ssize_t	ft_parse_precision(const char *format, t_line *line)
{
	ssize_t	i;

	i = -1;
	line->prec = ON;
	if (*format == '.')
		format++;
	if (ft_precision_str(format, line) == ON)
		return (ON);
	return (ft_get_precision(format, line, i));
}

static int	ft_precision_str(const char *format, t_line *line)
{
	if (*format == 's')
	{
		line->prec = FAIL;
		return (ON);
	}
	return (OFF);
}

static int	ft_get_precision(const char *format, t_line *line, int i)
{
	while (format[++i])
	{
		if (ft_check_spec(format, i) == ON)
			return (i + 1);
		if (format[i] == '-')
			return (i + 1 + ft_parse_minus((format + i), line));
		else if (format[i] >= '1' && format[i] <= '9')
		{
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			if (line->prec == FAIL)
			{
				i--;
				continue ;
			}
			line->prec = ft_get_combination_nbr(format,
					DEFAULT_INIT, i--, DEFAULT_INIT);
		}
		else if (format[i] == '0')
			line->prec = FAIL;
	}
	return (i + 1);
}
