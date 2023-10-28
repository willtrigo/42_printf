/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:14:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/28 00:03:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static void	ft_nbr_add(int nbr, t_line *line);
static void	ft_unbr_add(t_ui unbr, t_line *line);

void	ft_cast_int(va_list ap, t_line *line, t_line *format, int spec)
{
	int		nbr;
	t_ui	unbr;

	nbr = DEFAULT_INIT;
	unbr = DEFAULT_INIT;
	if (spec == CHK_INT_D_I)
	{
		nbr = va_arg(ap, int);
		ft_nbr_add(nbr, line);
	}
	else
	{
		unbr = va_arg(ap, t_ui);
		ft_unbr_add(unbr, line);
	}
	ft_format_jump(format);
}

static void	ft_nbr_add(int nbr, t_line *line)
{
	t_li	nbr_new;

	nbr_new = nbr;
	if (nbr == DEFAULT_INIT)
		ft_chr_add(&line->str, ft_chr_new('0'), line);
	else
	{
		if (!nbr)
			ft_str_add(NULL_STR, line);
		else
		{
			if (nbr_new < DEFAULT_INIT)
			{
				nbr_new *= -1;
				ft_chr_add(&line->str, ft_chr_new('-'), line);
			}
			if (nbr_new > 9)
				ft_nbr_add(nbr_new / 10, line);
			ft_chr_add(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}

static void	ft_unbr_add(t_ui unbr, t_line *line)
{
	t_uli	nbr_new;

	nbr_new = unbr;
	if (unbr == DEFAULT_INIT)
		ft_chr_add(&line->str, ft_chr_new('0'), line);
	else
	{
		if (!unbr)
			ft_str_add(NULL_STR, line);
		else
		{
			if (nbr_new < DEFAULT_INIT)
			{
				nbr_new *= -1;
				ft_chr_add(&line->str, ft_chr_new('-'), line);
			}
			if (nbr_new > 9)
				ft_nbr_add(nbr_new / 10, line);
			ft_chr_add(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}
