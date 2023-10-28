/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/27 23:09:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	ft_cast_str(va_list ap, t_line *line, t_line *format, int spec)
{
	char	*str;

	(void)spec;
	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	ft_str_add(str, line);
	ft_format_jump(format);
}

void	ft_str_add(char *str, t_line *line)
{
	while (*str)
		ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
}
