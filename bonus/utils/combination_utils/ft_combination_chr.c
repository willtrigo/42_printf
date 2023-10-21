/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_chr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 03:10:48 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 04:22:18 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_combination_head_chr(t_line *line)
{
	if (line->width >= ON && line->minus == OFF)
		while ((line->width-- - NULL_BYTE) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

void	ft_combination_tail_chr(t_line *line)
{
	if (line->width >= ON && line->minus >= ON)
		while ((line->width-- - NULL_BYTE) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}
