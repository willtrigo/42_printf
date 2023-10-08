/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/06 07:18:19 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

size_t	ft_cast_str(va_list ap, t_line *line)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	ft_add_str(str, line);
	return (JUMP_SPECIFIER);
}

void	ft_add_str(char *str, t_line *line)
{
	while (*str)
	{
		ft_add_char(&line->str, ft_char_new(*str));
		line->len++;
		str++;
	}
}
