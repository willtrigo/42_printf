/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:33:53 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 04:37:40 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

size_t	ft_cast_c(va_list ap, t_ln *ln)
{
	int	c;

	c = va_arg(ap, int);
	ft_add_c(&ln->str, ft_c_new(c), ln);
	return (JUMP_SPEC);
}
