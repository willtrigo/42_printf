/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_hex_math.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:05:13 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 06:57:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/ft_printf_bonus.h"

static void	ft_combination_hex_math_null_aux(t_line *line);
static void	ft_combination_hex_math_aux(t_line *line, t_hex_status *hex_status);

void	ft_combination_hex_math_null(t_line *line)
{
	if ((line->prec == OFF) && (line->zero == OFF) && (line->minus \
			== OFF) && (line->width == OFF))
		line->prec = ON;
	else if ((line->prec == OFF) && (line->zero == ON) && (line->minus \
				== OFF) && (line->width == OFF))
		line->prec = ON;
	else if ((line->prec == OFF) && (line->zero == OFF) && (line->minus \
				== OFF) && (line->width >= ON))
		line->prec = ON;
	else if ((line->prec == OFF) && (line->zero == OFF) && (line->minus \
				>= ON) && (line->width == OFF))
		line->prec = ON;
	if (line->prec == FAIL)
		line->zero = ON;
	ft_combination_hex_math_null_aux(line);
}

static void	ft_combination_hex_math_null_aux(t_line *line)
{
	if ((line->prec >= ON) && (line->width >= ON))
	{
		if (line->prec >= line->width)
			line->width = OFF;
		else if (line->prec < line->width)
			line->width -= line->prec;
	}
	else if ((line->prec >= ON) && (line->minus >= ON))
	{
		if (line->prec >= line->minus)
			line->minus = OFF;
		else if (line->prec < line->minus)
			line->minus -= line->prec;
	}
	if ((line->zero == ON) && (line->width >= ON) && (line->prec == OFF))
	{
		line->prec = line->width;
		line->width = OFF;
	}
}

void	ft_combination_hex_math(t_line *line, t_hex_status *hex_status)
{
	if ((line->minus >= ON) && (line->minus <= hex_status->len))
		line->minus = OFF;
	else if ((line->minus >= ON) && (line->minus > hex_status->len))
		line->minus -= hex_status->len;
	if ((line->zero == ON) && ((line->width >= ON) && (line->prec >= ON)))
	{
		if (line->prec >= line->width)
			line->width = OFF;
	}
	else if ((line->zero == ON) && ((line->width >= ON) && (line->prec \
				== OFF)))
	{
		line->prec = line->width;
		line->width = OFF;
	}
	ft_combination_hex_math_aux(line, hex_status);
}

static void	ft_combination_hex_math_aux(t_line *line, t_hex_status *hex_status)
{
	if ((line->prec >= ON) && (line->prec <= hex_status->len))
		line->prec = OFF;
	else if ((line->prec >= ON) && (line->prec > hex_status->len))
		line->prec -= hex_status->len;
	if ((line->plus >= ON) && (line->plus <= hex_status->len))
		line->plus = OFF;
	else if ((line->plus >= ON) && (line->plus > hex_status->len))
		line->plus -= hex_status->len;
	if (((line->minus >= ON) && (line->prec >= ON)) && (line->minus \
			<= line->prec))
		line->minus = OFF;
	else if (((line->minus >= ON) && (line->prec >= ON)) && (line->minus \
				> line->prec))
		line->minus -= line->prec;
	if ((line->width >= ON) && (line->width <= hex_status->len))
		line->width = OFF;
	else if ((line->width >= ON) && (line->width > hex_status->len))
		line->width -= hex_status->len;
	if (((line->width >= ON) && (line->prec >= ON)) && (line->width \
			<= line->prec))
		line->width = OFF;
	else if (((line->width >= ON) && (line->prec >= ON)) && (line->width \
				> line->prec))
		line->width -= line->prec;
}
