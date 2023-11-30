/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 08:01:38 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 22:19:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

void	ft_combination_head_str(t_line *line)
{
	if (line->width >= ON)
		ft_combination_add(line, ' ', line->width);
}

void	ft_combination_tail_str(t_line *line)
{
	if (line->minus >= ON)
		ft_combination_add(line, ' ', line->minus);
}
