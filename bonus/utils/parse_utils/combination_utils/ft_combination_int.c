/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 06:42:59 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 06:57:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

void	ft_combination_head_int(t_line *line, t_lli nbr)
{
	if (line->space == ON && nbr >= 0 && line->plus == OFF)
		ft_chr_add(&line->str, ft_chr_new(' '), line);
	else if (nbr >= 0 && line->plus == ON)
		ft_chr_add(&line->str, ft_chr_new('+'), line);
	if (line->width >= ON)
		ft_combination_add(line, ' ', line->width);
	if (nbr < 0)
	{
		if (line->zero == ON)
			ft_chr_add(&line->str, ft_chr_new('-'), line);
		else if ((line->width == OFF) && (line->prec == OFF)
			&& (line->minus == OFF))
			ft_chr_add(&line->str, ft_chr_new('-'), line);
	}
	if (line->prec >= ON)
		ft_combination_add(line, '0', line->prec);
}

void	ft_combination_tail_int(t_line *line)
{
	if (line->minus >= ON)
		ft_combination_add(line, ' ', line->minus);
}
