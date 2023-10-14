/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_combination.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:25:55 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/14 04:52:55 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static ssize_t	ft_parse_space(const char *format, t_line *line);
static ssize_t	ft_parse_plus(const char *format, t_line *line);

size_t	ft_parse_combination(const char *format, t_line *line)
{
	const char	*next_chr = format;

	if (*next_chr == 'c' || *next_chr == 's' || *next_chr == 'p'\
		|| *next_chr == 'd' || *next_chr == 'i' || *next_chr == 'u'\
		|| *next_chr == 'x' || *next_chr == 'X' || *next_chr == '%')
		return (OFF);
	while (*next_chr)
	{
		if (*next_chr == '#')
		{
			line->hash = ON;
			return (JUMP);
		}
		else if (*next_chr == ' ')
			return (ft_parse_space(next_chr, line));
		else if (*next_chr == '+')
			return (ft_parse_plus(next_chr, line));
		next_chr++;
	}
	return (OFF);
}

static ssize_t	ft_parse_space(const char *format, t_line *line)
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

static ssize_t	ft_parse_plus(const char *format, t_line *line)
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
