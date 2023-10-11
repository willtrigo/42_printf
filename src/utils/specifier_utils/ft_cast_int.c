/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:14:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 07:34:24 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static void	ft_addnbr(int nbr, t_ln *ln);
static void	ft_addunbr(unsigned int unbr, t_ln *ln);

size_t	ft_cast_int(va_list ap, t_ln *ln, int spec)
{
	int				nbr;
	unsigned int	unbr;

	nbr = 0;
	unbr = 0;
	if (spec == CHK_INT_D_I)
	{
		nbr = va_arg(ap, int);
		ft_addnbr(nbr, ln);
	}
	else
	{
		unbr = va_arg(ap, unsigned int);
		ft_addunbr(unbr, ln);
	}
	return (JUMP_SPEC);
}

static void	ft_addnbr(int nbr, t_ln *ln)
{
	long int	nbr_new;

	nbr_new = nbr;
	if (nbr == 0)
		ft_add_c(&ln->str, ft_c_new('0'), ln);
	else
	{
		if (!nbr)
			ft_add_str(NULL_STR, ln);
		else
		{
			if (nbr_new < 0)
			{
				nbr_new *= -1;
				ft_add_c(&ln->str, ft_c_new('-'), ln);
			}
			if (nbr_new > 9)
				ft_addnbr(nbr_new / 10, ln);
			ft_add_c(&ln->str, ft_c_new(nbr_new % 10 + '0'), ln);
		}
	}
}

static void	ft_addunbr(unsigned int unbr, t_ln *ln)
{
	unsigned long int	nbr_new;

	nbr_new = unbr;
	if (unbr == 0)
		ft_add_c(&ln->str, ft_c_new('0'), ln);
	else
	{
		if (!unbr)
			ft_add_str(NULL_STR, ln);
		else
		{
			if (nbr_new < 0)
			{
				nbr_new *= -1;
				ft_add_c(&ln->str, ft_c_new('-'), ln);
			}
			if (nbr_new > 9)
				ft_addnbr(nbr_new / 10, ln);
			ft_add_c(&ln->str, ft_c_new(nbr_new % 10 + '0'), ln);
		}
	}
}
