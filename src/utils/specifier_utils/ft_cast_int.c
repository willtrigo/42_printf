/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:14:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/08 00:12:59 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static void	ft_addnbr(int nbr, t_line *line);
static void	ft_addunbr(unsigned int unbr, t_line *line);

size_t	ft_cast_int(va_list ap, t_line *line, int speficier)
{
	int				nbr;
	unsigned int	unbr;

	nbr = 0;
	unbr = 0;
	if (speficier == CHECK_INT_D_I)
	{
		nbr = va_arg(ap, int);
		ft_addnbr(nbr, line);
	}
	else
	{
		unbr = va_arg(ap, unsigned int);
		ft_addunbr(unbr, line);
	}
	return (JUMP_SPECIFIER);
}

static void	ft_addnbr(int nbr, t_line *line)
{
	long int	nbr_new;

	nbr_new = nbr;
	if (!nbr)
		ft_add_str(NULL_STR, line);
	else
	{
		if (nbr_new < 0)
		{
			nbr_new *= -1;
			ft_add_char(&line->str, ft_char_new('-'));
			line->len++;
		}
		if (nbr_new > 9)
			ft_addnbr(nbr_new / 10, line);
		ft_add_char(&line->str, ft_char_new(nbr_new % 10 + '0'));
		line->len++;
	}
}

static void	ft_addunbr(unsigned int unbr, t_line *line)
{
	unsigned long int	nbr_new;

	nbr_new = unbr;
	if (!unbr)
		ft_add_str(NULL_STR, line);
	else
	{
		if (nbr_new < 0)
		{
			nbr_new *= -1;
			ft_add_char(&line->str, ft_char_new('-'));
			line->len++;
		}
		if (nbr_new > 9)
			ft_addnbr(nbr_new / 10, line);
		ft_add_char(&line->str, ft_char_new(nbr_new % 10 + '0'));
		line->len++;
	}
}
