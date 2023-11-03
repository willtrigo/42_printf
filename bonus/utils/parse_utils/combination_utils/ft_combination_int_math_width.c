/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_int_math_width.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 05:39:31 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 06:57:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

static void	ft_int_math_width_aux(t_line *line, t_lli nbr,
				t_combination_history *hist);
static void	ft_int_math_width_aux_1(t_line *line, t_lli nbr,
				t_combination_history *hist);
static void	ft_int_math_width_aux_2(t_line *line, t_lli nbr,
				t_combination_history *hist);

void	ft_int_math_width(t_line *line, t_lli nbr, t_combination_history *hist)
{
	if (((nbr < 0) || (hist->len == BYTE)) && (hist->prec == BYTE))
	{
		ft_math_apply(line, OFF, OFF, line->minus);
		line->zero = ON;
		return ;
	}
	else if ((hist->width < hist->len) && (hist->prec > hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, OFF, line->minus);
		if (nbr < 0)
		{
			ft_math_apply(line, ++line->prec, OFF, line->minus);
			line->zero = ON;
		}
		return ;
	}
	ft_int_math_width_aux(line, nbr, hist);
}

static void	ft_int_math_width_aux(t_line *line, t_lli nbr,
				t_combination_history *hist)
{
	if ((hist->width == hist->len) && (hist->prec > hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, OFF, line->minus);
		if (nbr < 0)
		{
			ft_math_apply(line, --line->prec, OFF, line->minus);
			line->zero = ON;
		}
		return ;
	}
	else if ((hist->width > hist->len) && (hist->prec >= hist->len))
	{
		ft_math_apply(line, line->prec - hist->len, line->width \
			- hist->prec, line->minus);
		if (nbr < 0)
		{
			ft_math_apply(line, ++line->prec, --line->width, line->minus);
			line->zero = ON;
		}
		return ;
	}
	ft_int_math_width_aux_1(line, nbr, hist);
}

static void	ft_int_math_width_aux_1(t_line *line, t_lli nbr,
				t_combination_history *hist)
{
	if ((hist->width > hist->len) && (hist->prec < hist->len))
	{
		ft_math_apply(line, OFF, line->width - hist->len, line->minus);
		if (nbr < 0)
			line->zero = ON;
		return ;
	}
	else if (hist->width == hist->prec)
	{
		ft_math_apply(line, line->prec - hist->len, line->width \
			- hist->len, line->minus);
		if (nbr < 0)
		{
			ft_math_apply(line, ++line->prec, line->width, line->minus);
			line->zero = ON;
		}
		return ;
	}
	ft_int_math_width_aux_2(line, nbr, hist);
}

static void	ft_int_math_width_aux_2(t_line *line, t_lli nbr,
				t_combination_history *hist)
{
	if ((hist->width <= hist->len) && ((line->zero == OFF) \
		&& (hist->prec == OFF) && (hist->minus == OFF)))
		ft_math_apply(line, OFF, line->width - hist->len, OFF);
	else if ((hist->len > hist->width) && (hist->len > hist->prec))
		ft_math_apply(line, OFF, OFF, line->minus);
	if (nbr < 0)
		line->zero = ON;
}
