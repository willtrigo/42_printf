/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:14:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/07 20:07:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static void	ft_int_add(t_lli nbr, t_line *line);

void	ft_cast_int(va_list ap, t_line *line, t_line *format, int spec)
{
	int		nbr;
	t_ui	unbr;

	nbr = DEFAULT_INIT;
	unbr = DEFAULT_INIT;
	if (spec == CHK_INT_D_I)
	{
		nbr = va_arg(ap, int);
		ft_int_add((t_lli)nbr, line);
	}
	else
	{
		unbr = va_arg(ap, t_ui);
		ft_int_add((t_lli)unbr, line);
	}
	ft_format_jump(format);
}

static void	ft_int_add(t_lli nbr, t_line *line)
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
				ft_int_add(nbr_new / 10, line);
			ft_chr_add(&line->str, ft_chr_new(nbr_new % 10 + '0'), line);
		}
	}
}
