/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 00:59:18 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

size_t	ft_cast_str(va_list ap, t_line *line, int spec)
{
	char	*str;

	(void)spec;
	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	ft_str_add(str, line);
	return (JUMP);
}

void	ft_str_add(char *str, t_line *line)
{
	while (*str)
		ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
}
