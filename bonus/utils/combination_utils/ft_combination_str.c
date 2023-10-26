/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:01:38 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/25 20:58:29 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_reset_prec(t_line *line);

void	ft_combination_head_str(t_line *line, char *str)
{
	const int	str_len = ft_str_len((const char *)str);

	if (*str == '\0')
	{
		if (line->prec < ON && *str == '\0')
			ft_chr_add(&line->str, ft_chr_new(' '), line);
		ft_reset_prec(line);
	}
	else if (line->prec >= ON || line->width >= ON)
	{
		if (line->prec >= ON)
		{
			if (str_len < line->prec)
				line->prec = str_len;
			else if (line->width > line->prec)
				line->width -= line->prec - str_len;
		}
		while ((line->width-- - NULL_BYTE - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	}
}

void	ft_combination_tail_str(t_line *line, int str_len)
{
	line->minus -= str_len;
	if (line->prec >= ON)
		line->minus -= line->prec + NULL_BYTE;
	if (line->minus >= ON)
		while ((line->minus--) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

static void	ft_reset_prec(t_line *line)
{
	line->prec = OFF;
	line->width = OFF;
}
