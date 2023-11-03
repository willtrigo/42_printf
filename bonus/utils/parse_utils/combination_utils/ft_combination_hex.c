/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:56:07 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 06:57:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

void	ft_combination_head_hex(t_line *line)
{
	if (line->plus >= ON)
		ft_combination_add(line, ' ', line->plus);
	if (line->width >= ON)
		ft_combination_add(line, ' ', line->width);
	if (line->prec >= ON)
		ft_combination_add(line, '0', line->prec);
}

void	ft_combination_tail_hex(t_line *line)
{
	if (line->minus >= ON)
		ft_combination_add(line, ' ', line->minus);
}
