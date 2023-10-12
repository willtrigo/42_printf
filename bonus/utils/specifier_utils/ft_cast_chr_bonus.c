/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_chr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:33:53 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/12 12:13:56 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_chr(va_list ap, t_line *line, int spec)
{
	const int	chr = va_arg(ap, int);

	(void)spec;
	ft_add_chr(&line->str, ft_chr_new(chr), line);
	return (0);
}
