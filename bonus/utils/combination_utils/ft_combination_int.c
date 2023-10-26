/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 06:42:59 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:44:59 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_combination_head_aux_minus(t_line *line, t_lli nbr_len);

void	ft_combination_head_nbr(t_line *line, t_lli nbr_len, int fn_nbr)
{
	ft_combination_head_aux_minus(line, nbr_len);
	if (fn_nbr < 0)
	{
		ft_chr_add(&line->str, ft_chr_new('-'), line);
		if (line->prec >= ON)
			nbr_len--;
	}
	if (line->width >= ON && line->zero == OFF && line->minus
		== OFF && line->prec == OFF)
	{
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	}
	if (line->prec >= ON)
		while ((line->prec-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
	if (line->zero >= ON)
		while ((line->zero-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
}

void	ft_combination_head_aux_minus(t_line *line, t_lli nbr_len)
{
	if (line->prec >= ON)
	{
		if (line->minus < line->prec)
			line->minus -= line->prec + nbr_len;
		else if (line->prec < nbr_len)
			line->minus -= (line->prec - nbr_len) + (line->minus - nbr_len) + 1;
		else if (line->minus > line->prec)
			line->minus -= line->prec - nbr_len;
	}
}

void	ft_combination_tail_nbr(t_line *line, t_lli nbr_len)
{
	if (line->minus >= ON)
		while (line->minus-- - nbr_len > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

void	ft_combination_head_unbr(t_line *line, t_lli nbr_len, t_ui fn_nbr)
{
	if (line->prec >= ON)
	{
		if (line->minus < line->prec)
			line->minus -= line->prec + nbr_len;
		else if (line->prec < nbr_len)
			line->minus -= (line->prec - nbr_len) + (line->minus - nbr_len) + 1;
		else if (line->minus > line->prec)
			line->minus -= line->prec - nbr_len;
	}
	if (fn_nbr < 0)
		ft_chr_add(&line->str, ft_chr_new('-'), line);
	if (line->width >= ON && line->zero == OFF && line->minus
		== OFF && line->prec == OFF)
	{
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	}
	if (line->prec >= ON)
		while ((line->prec-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
	if (line->zero >= ON)
		while ((line->zero-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
}

void	ft_combination_tail_unbr(t_line *line, t_lli nbr_len)
{
	if (line->minus >= ON)
		while (line->minus-- - nbr_len > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}
