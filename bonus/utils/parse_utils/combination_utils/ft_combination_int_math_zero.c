/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_int_math_zero.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 04:15:37 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 06:57:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

static void	ft_int_math_zero_aux(t_line *line, t_lli nbr,
				t_combination_history *hist);

void	ft_int_math_zero(t_line *line, t_lli nbr, t_combination_history *hist)
{
	if (((nbr < 0) || (hist->len == BYTE)) && ((hist->width == BYTE) \
		&& (hist->prec == BYTE)))
	{
		ft_math_apply(line, OFF, OFF, line->minus);
		return ;
	}
	if ((hist->width < hist->len) && (hist->prec > hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, OFF, line->minus);
		if (nbr < 0)
			ft_math_apply(line, ++line->prec, line->width, line->minus);
	}
	ft_int_math_zero_aux(line, nbr, hist);
}

static void	ft_int_math_zero_aux(t_line *line, t_lli nbr,
				t_combination_history *hist)
{
	if ((hist->width == hist->len) && (hist->prec > hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, OFF, line->minus);
		if (nbr < 0)
			ft_math_apply(line, line->prec - hist->len \
				- BYTE, OFF, line->minus);
	}
	else if (hist->width == hist->len)
		ft_math_apply(line, line->prec, OFF, line->minus);
	else if (hist->width == hist->prec)
	{
		ft_math_apply(line, line->prec - hist->len, line->width \
			- hist->len, line->minus);
		if (nbr < 0)
			ft_math_apply(line, ++line->prec, line->width, line->minus);
	}
	else if ((hist->width > hist->len) && (hist->prec == OFF))
		ft_math_apply(line, hist->width - hist->len, OFF, line->minus);
}
