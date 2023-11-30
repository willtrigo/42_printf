/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_str_math.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:14:40 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/05 07:23:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

static void	ft_combination_str_math_aux(t_line *line, char *str,
				t_combination_history *hist);
static void	ft_combination_str_single(t_line *line, char *str,
				t_combination_history *hist);
static void	ft_combination_str_mix(t_line *line, char *str,
				t_combination_history *hist);
static void	ft_combination_str_zero(t_line *line,
				t_combination_history *hist);

void	ft_combination_str_math(t_line *line, char *str, int str_len)
{
	t_combination_history	hist;

	hist.len = str_len;
	hist.prec = line->prec;
	hist.width = line->width;
	hist.minus = line->minus;
	ft_combination_str_math_aux(line, str, &hist);
}

static void	ft_combination_str_math_aux(t_line *line, char *str,
				t_combination_history *hist)
{
	if ((hist->len == OFF) && (line->space == ON))
	{
		if (hist->prec >= ON)
			ft_math_apply(line, OFF, hist->prec, OFF);
		return ;
	}
	if (!str)
	{
		ft_combination_str_null(line, hist);
		return ;
	}
	ft_combination_str_single(line, str, hist);
	ft_combination_str_mix(line, str, hist);
	ft_combination_str_zero(line, hist);
}

static void	ft_combination_str_single(t_line *line, char *str,
				t_combination_history *hist)
{
	if ((hist->prec >= ON) && ((hist->width == OFF) && (hist->minus \
		== OFF) && (line->zero == OFF)))
	{
		if (((hist->prec < ft_str_len(str)) && (hist->prec != OFF)) \
			&& (hist->minus == OFF) && (line->zero == OFF) \
			&& (hist->width == OFF))
			ft_math_apply(line, hist->prec, OFF, OFF);
		if ((hist->minus == OFF) && (hist->width == OFF))
			ft_math_apply(line, hist->prec, OFF, OFF);
	}
	if ((hist->width >= ON) && (line->zero == OFF))
	{
		if (hist->prec == FAIL)
			ft_math_apply(line, hist->width, OFF, OFF);
		if ((hist->minus == OFF) && (hist->prec == OFF))
			ft_math_apply(line, OFF, hist->width - ft_str_len(str), OFF);
	}
	if ((hist->minus >= ON) && (line->zero == OFF))
	{
		if (hist->prec == FAIL)
			ft_math_apply(line, hist->prec, OFF, line->minus);
		if ((hist->width == OFF) && (hist->prec == OFF))
			ft_math_apply(line, OFF, OFF, hist->minus - ft_str_len(str));
	}
}

static void	ft_combination_str_mix(t_line *line, char *str,
				t_combination_history *hist)
{
	if ((hist->width >= ON) && (hist->prec != OFF) && (line->zero == OFF))
	{
		if (hist->prec == FAIL)
			ft_math_apply(line, hist->prec, --hist->width, OFF);
		if (hist->prec >= ft_str_len(str))
			ft_math_apply(line, hist->prec, hist->width - ft_str_len(str), OFF);
		else if (hist->prec < ft_str_len(str))
			ft_math_apply(line, hist->prec, hist->width - hist->prec, OFF);
	}
	if ((hist->minus >= ON) && (hist->prec != OFF) && (line->zero == OFF))
	{
		if (hist->prec == FAIL)
			ft_math_apply(line, hist->prec, OFF, --hist->minus);
		if (hist->prec >= ft_str_len(str))
			ft_math_apply(line, hist->prec, OFF, hist->minus - ft_str_len(str));
		else if (hist->prec < ft_str_len(str))
			ft_math_apply(line, hist->prec, OFF, hist->minus - hist->prec);
	}
}

static void	ft_combination_str_zero(t_line *line,
				t_combination_history *hist)
{
	if (line->zero == ZERO)
	{
		if (hist->prec == ZERO)
			ft_math_apply(line, FAIL, OFF, OFF);
		if (hist->width >= ON)
			ft_math_apply(line, FAIL, hist->width, OFF);
		if (hist->minus >= ON)
			ft_math_apply(line, FAIL, hist->minus, OFF);
	}
	if (line->zero == ON)
	{
		if (hist->width >= ON)
			ft_math_apply(line, hist->width, OFF, OFF);
		if (hist->minus >= ON)
			ft_math_apply(line, FAIL, hist->width, hist->minus);
	}
}
