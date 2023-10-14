/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_int_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:14:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/14 02:29:59 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_addnbr(int nbr, t_line *line);
static void	ft_addunbr(t_ui unbr, t_line *line);

size_t	ft_cast_int(va_list ap, t_line *line, int spec)
{
	int		nbr;
	t_ui	unbr;

	nbr = 0;
	unbr = 0;
	if (spec == CHK_INT_D_I)
	{
		nbr = va_arg(ap, int);
		if (line->space == ON && nbr >= 0 && line->plus == OFF)
			ft_add_chr(&line->str, ft_chr_new(' '), line);
		else if (nbr >= 0 && line->plus == ON)
			ft_add_chr(&line->str, ft_chr_new('+'), line);
		line->space = OFF;
		line->plus = OFF;
		ft_addnbr(nbr, line);
	}
	else
	{
		unbr = va_arg(ap, t_ui);
		ft_addunbr(unbr, line);
	}
	return (JUMP);
}

static void	ft_addnbr(int nbr, t_line *line)
{
	t_li	nbr_new;

	nbr_new = nbr;
	if (nbr == 0)
		ft_add_chr(&line->str, ft_chr_new('0'), line);
	else
	{
		if (!nbr)
			ft_add_str(NULL_STR, line);
		else
		{
			if (nbr_new < 0)
			{
				nbr_new *= -1;
				ft_add_chr(&line->str, ft_chr_new('-'), line);
			}
			if (nbr_new > 9)
				ft_addnbr(nbr_new / 10, line);
			ft_add_chr(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}

static void	ft_addunbr(t_ui unbr, t_line *line)
{
	t_uli	nbr_new;

	nbr_new = unbr;
	if (unbr == 0)
		ft_add_chr(&line->str, ft_chr_new('0'), line);
	else
	{
		if (!unbr)
			ft_add_str(NULL_STR, line);
		else
		{
			if (nbr_new < 0)
			{
				nbr_new *= -1;
				ft_add_chr(&line->str, ft_chr_new('-'), line);
			}
			if (nbr_new > 9)
				ft_addnbr(nbr_new / 10, line);
			ft_add_chr(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}
