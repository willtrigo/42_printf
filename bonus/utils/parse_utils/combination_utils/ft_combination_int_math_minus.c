/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_int_math_minus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 06:39:04 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 06:57:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

static void	ft_int_math_minus_aux(t_line *line, t_lli nbr,
				t_combination_history *hist);
static void	ft_int_math_minus_aux_1(t_line *line, t_lli nbr,
				t_combination_history *hist);

void	ft_int_math_minus(t_line *line, t_lli nbr, t_combination_history *hist)
{
	if (((nbr < 0) || (hist->len == BYTE)) && ((hist->width == BYTE) \
		|| (hist->prec == BYTE)))
	{
		ft_math_apply(line, OFF, OFF, --line->minus);
		if (nbr < 0)
			line->zero = ON;
		return ;
	}
	else if ((hist->minus < hist->len) && (hist->prec > hist->len))
	{
		ft_math_apply(line, line->prec -= hist->len, line->width, OFF);
		if (nbr < 0)
		{
			ft_math_apply(line, ++line->prec, line->width, line->minus);
			line->zero = ON;
		}
		return ;
	}
	ft_int_math_minus_aux(line, nbr, hist);
}

static void	ft_int_math_minus_aux(t_line *line, t_lli nbr,
				t_combination_history *hist)
{
	if ((hist->minus == hist->len) && (hist->prec > hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, line->width, OFF);
		if (nbr < 0)
		{
			ft_math_apply(line, line->prec - hist->len \
				- BYTE, line->width, OFF);
			line->zero = ON;
		}
		return ;
	}
	else if ((hist->minus > hist->len) && (hist->prec >= hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, line->width, line->minus \
			- hist->prec);
		if (nbr < 0)
		{
			ft_math_apply(line, ++line->prec, line->width, --line->minus);
			line->zero = ON;
		}
		return ;
	}
	ft_int_math_minus_aux_1(line, nbr, hist);
}

static void	ft_int_math_minus_aux_1(t_line *line, t_lli nbr,
				t_combination_history *hist)
{
	if ((hist->minus > hist->len) && (hist->prec < hist->len))
		ft_math_apply(line, OFF, line->width, line->minus - hist->len);
	else if (hist->minus == hist->prec)
	{
		ft_math_apply(line, line->prec - hist->len, line->width, line->minus \
			- hist->len);
		if (nbr < 0)
			ft_math_apply(line, ++line->prec, line->width, line->minus);
	}
	else
		ft_math_apply(line, hist->minus - hist->len, line->width, OFF);
	if (nbr < 0)
		line->zero = ON;
}
