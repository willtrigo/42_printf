/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/18 19:30:42 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

int			ft_str_len(const char *str);
static void	ft_parse_str_prec(const char *str, t_line *line);
static void	ft_reset_prec(t_line *line);

size_t	ft_cast_str(va_list ap, t_line *line, int spec)
{
	int		str_len;
	char	*str;

	(void)spec;
	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	else if (line->prec >= ON)
		ft_parse_str_prec(str, line);
	str_len = ft_str_len((const char *)str);
	if (*str != '\0')
		ft_str_add(str, line);
	if (line->width >= ON && line->minus >= ON)
		while ((line->width-- - 1 - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->width >= ON && line->minus >= OFF)
		while ((line->width-- - 1 - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	return (JUMP);
}

void	ft_str_add(char *str, t_line *line)
{
	while (*(str + line->prec))
		ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
}

int	ft_str_len(const char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

static void	ft_parse_str_prec(const char *str, t_line *line)
{
	const int	str_len = ft_str_len((const char *)str);

	if (*str == '\0')
		ft_reset_prec(line);
	else if (line->prec >= ON)
	{
		if (str_len <= ON)
		{
			if (line->width >= ON)
				ft_reset_prec(line);
		}
		if ((str_len > ON))
		{
			if (str_len == line->width)
				ft_reset_prec(line);
			else if (str_len > line->width)
				line->prec = str_len - line->width;
			else if ((str_len - line->prec) > ON)
				line->prec = (line->width - line->prec) - str_len;
		}
	}
}

static void	ft_reset_prec(t_line *line)
{
	line->prec = 0;
	line->width = 0;
}
