/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_char_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:33:53 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/09 05:01:27 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_char(va_list ap, t_line *line)
{
	int	c;

	c = va_arg(ap, int);
	ft_add_char(&line->str, ft_char_new(c), line);
	return (JUMP_SPECIFIER);
}
