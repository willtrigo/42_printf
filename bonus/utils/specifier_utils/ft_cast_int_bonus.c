/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_int_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:14:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/28 08:23:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_nbr_add(int nbr, t_line *line);
static void	ft_unbr_add(t_ui unbr, t_line *line);
static void	ft_combination_nbr_add(t_line *line, t_lli nbr,
				void (*fn_add)(int, t_line *), int fn_nbr);
static void	ft_combination_unbr_add(t_line *line, t_lli nbr,
				void (*fn_add)(t_ui, t_line *), t_ui ft_nbr);

void	ft_cast_int(va_list ap, t_line *line, t_line *format, int spec)
{
	int		nbr;
	t_ui	unbr;

	nbr = 0;
	unbr = 0;
	if (spec == CHK_INT_D_I)
	{
		nbr = va_arg(ap, int);
		if (line->space == ON && nbr >= 0 && line->plus == OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
		else if (nbr >= 0 && line->plus == ON)
			ft_chr_add(&line->str, ft_chr_new('+'), line);
		ft_combination_nbr_add(line, (t_lli)nbr, ft_nbr_add, nbr);
	}
	else
	{
		unbr = va_arg(ap, t_ui);
		ft_combination_unbr_add(line, (t_lli)unbr, ft_unbr_add, unbr);
	}
	ft_format_jump(format);
}

static void	ft_nbr_add(int nbr, t_line *line)
{
	t_lli	nbr_new;

	nbr_new = nbr;
	if (nbr == 0)
		ft_chr_add(&line->str, ft_chr_new('0'), line);
	else
	{
		if (!nbr)
			ft_str_add(NULL_STR, line);
		else
		{
			if (nbr_new < 0)
				nbr_new *= -1;
			if (nbr_new > 9)
				ft_nbr_add(nbr_new / 10, line);
			ft_chr_add(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}

static void	ft_unbr_add(t_ui unbr, t_line *line)
{
	t_ulli	nbr_new;

	nbr_new = unbr;
	if (unbr == 0)
		ft_chr_add(&line->str, ft_chr_new('0'), line);
	else
	{
		if (!unbr)
			ft_str_add(NULL_STR, line);
		else
		{
			if (nbr_new < 0)
				nbr_new *= -1;
			if (nbr_new > 9)
				ft_nbr_add(nbr_new / 10, line);
			ft_chr_add(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}

static void	ft_combination_nbr_add(t_line *line, t_lli nbr,
				void (*fn_add)(int, t_line *), int fn_nbr)
{
	t_lli	nbr_len;

	nbr_len = ft_get_nbr_len(nbr);
	ft_combination_head_nbr(line, nbr_len, fn_nbr);
	fn_add(fn_nbr, line);
	ft_combination_tail_nbr(line, nbr_len);
}

static void	ft_combination_unbr_add(t_line *line, t_lli nbr,
				void (*fn_add)(t_ui, t_line *), t_ui fn_nbr)
{
	t_lli	nbr_len;

	nbr_len = ft_get_nbr_len(nbr);
	ft_combination_head_unbr(line, nbr_len, fn_nbr);
	fn_add(fn_nbr, line);
	ft_combination_tail_unbr(line, nbr_len);
}
