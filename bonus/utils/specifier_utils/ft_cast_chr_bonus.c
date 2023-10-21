/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_chr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:33:53 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 03:41:31 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_chr(va_list ap, t_line *line, int spec)
{
	const int	chr = va_arg(ap, int);

	(void)spec;
	ft_combination_head_chr(line);
	ft_chr_add(&line->str, ft_chr_new(chr), line);
	ft_combination_tail_chr(line);
	return (0);
}
