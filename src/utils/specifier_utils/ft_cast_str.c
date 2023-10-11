/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 07:35:14 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

size_t	ft_cast_str(va_list ap, t_ln *ln)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	ft_add_str(str, ln);
	return (JUMP_SPEC);
}

void	ft_add_str(char *str, t_ln *ln)
{
	while (*str)
		ft_add_c(&ln->str, ft_c_new(*(str++)), ln);
}
