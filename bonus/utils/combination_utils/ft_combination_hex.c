/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:56:07 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/22 12:28:05 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_combination_tail_hex_ptr(t_line *line, t_hex_status *hex_status)
{
	if (line->width >= ON && line->minus == OFF)
		while ((line->width-- - hex_status->len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->minus >= ON)
		while ((line->minus-- - hex_status->len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

void	ft_combination_head_hex_lw_up(t_line *line, t_hex_status *hex_status)
{
	if ((line->zero >= ON) || (line->prec >= ON))
	{
		if (line->prec >= ON && (hex_status->len == line->prec))
			line->prec = 0;
		while ((line->zero-- - hex_status->len) > OFF)
			ft_chr_add(&line->str, ft_chr_new('0'), line);
		if (hex_status->len < line->prec && line->prec >= ON)
			while ((line->prec-- - hex_status->len) > OFF)
				ft_chr_add(&line->str, ft_chr_new('0'), line);
	}
}

void	ft_combination_tail_hex_lw_up(t_line *line,
			t_ulli hex, t_hex_status *hex_status)
{
	if (line->width >= ON && line->minus == OFF)
		while (line->width-- - 1 - hex_status->len > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (hex == 0)
		line->minus = OFF;
	if (line->minus >= ON)
		while ((line->minus-- - hex_status->len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}
