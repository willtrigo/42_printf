/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_str_math_null.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 07:07:31 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/05 07:22:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

static void	ft_combination_str_null_precision(t_line *line);
static void	ft_combination_str_null_width(t_line *line,
				t_combination_history *hist);
static void	ft_combination_str_null_minus(t_line *line,
				t_combination_history *hist);

void	ft_combination_str_null(t_line *line,
				t_combination_history *hist)
{
	if (((line->prec < ft_str_len(NULL_STR)) && (line->prec != OFF)) && \
		(line->minus == OFF) && (line->zero == OFF))
		ft_math_apply(line, FAIL, OFF, OFF);
	else if ((line->prec == FAIL) && (line->minus >= ON))
		ft_math_apply(line, FAIL, OFF, line->minus);
	else if ((line->prec == FAIL) && (line->zero >= ON))
	{
		if (line->width < ft_str_len(NULL_STR))
			ft_math_apply(line, FAIL, OFF, OFF);
		else
			ft_math_apply(line, OFF, OFF, OFF);
		return ;
	}
	else if (line->prec >= ON)
		ft_combination_str_null_precision(line);
	ft_combination_str_null_width(line, hist);
	ft_combination_str_null_minus(line, hist);
}

static void	ft_combination_str_null_precision(t_line *line)
{
	if ((line->minus == FAIL) && (line->prec < ft_str_len(NULL_STR)) \
			&& (line->zero == OFF))
		ft_math_apply(line, FAIL, OFF, OFF);
	else if ((line->minus >= ON) && (line->prec < ft_str_len(NULL_STR)))
		ft_math_apply(line, FAIL, OFF, line->minus);
	else if ((line->minus < ft_str_len(NULL_STR)) && (line->prec < \
				ft_str_len(NULL_STR)))
		ft_math_apply(line, FAIL, OFF, OFF);
	else if ((line->minus <= ft_str_len(NULL_STR)) && (line->prec >= \
				ft_str_len(NULL_STR)))
		ft_math_apply(line, OFF, OFF, OFF);
	else if ((line->minus >= ft_str_len(NULL_STR)) && (line->prec >= \
				ft_str_len(NULL_STR)))
		ft_math_apply(line, OFF, OFF, line->minus - \
			ft_str_len(NULL_STR));
}

static void	ft_combination_str_null_width(t_line *line,
				t_combination_history *hist)
{
	if (hist->width >= ON)
	{
		if ((line->prec == FAIL) && (line->prec < ft_str_len(NULL_STR)))
			ft_math_apply(line, FAIL, OFF, hist->width);
		else
			ft_math_apply(line, OFF, hist->width \
				- ft_str_len(NULL_STR), OFF);
	}
}

static void	ft_combination_str_null_minus(t_line *line,
				t_combination_history *hist)
{
	if (hist->minus >= ON)
	{
		if ((line->prec == FAIL) && (line->prec < ft_str_len(NULL_STR)))
			ft_math_apply(line, FAIL, OFF, hist->minus);
		else
			ft_math_apply(line, OFF, OFF, hist->minus \
			- ft_str_len(NULL_STR));
	}
}
