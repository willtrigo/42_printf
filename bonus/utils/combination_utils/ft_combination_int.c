/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combination_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 06:42:59 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 08:11:26 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_combination_head_nbr(t_line *line, t_lli nbr_len, int fn_nbr)
{
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
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
	if (line->width >= ON && line->zero >= ON)
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
}

void	ft_combination_tail_nbr(t_line *line, t_lli nbr_len)
{
	if (line->width >= ON && line->zero == OFF && line->minus >= ON)
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

void	ft_combination_head_unbr(t_line *line, t_lli nbr_len, t_ui fn_nbr)
{
	if (fn_nbr < 0)
		ft_chr_add(&line->str, ft_chr_new('-'), line);
	if (line->width >= ON && line->zero == OFF && line->minus
		== OFF && line->prec == OFF)
	{
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	}
	if (line->prec >= ON)
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
	if (line->width >= ON && line->zero >= ON)
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new('0'), line);
}

void	ft_combination_tail_unbr(t_line *line, t_lli nbr_len)
{
	if (line->width >= ON && line->zero == OFF && line->minus >= ON)
		while ((line->width-- - nbr_len > OFF))
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}
