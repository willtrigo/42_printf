/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:01:38 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 10:08:04 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_reset_prec(t_line *line);

void	ft_combination_head_str(t_line *line, char *str)
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

void	ft_combination_tail_str(t_line *line, int str_len)
{
	if (line->width >= ON && line->minus >= ON)
		while ((line->width-- - 1 - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->width >= ON && line->minus >= OFF)
		while ((line->width-- - 1 - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

static void	ft_reset_prec(t_line *line)
{
	line->prec = 0;
	line->width = 0;
}
