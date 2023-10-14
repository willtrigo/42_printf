/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/14 01:22:35 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_str(va_list ap, t_line *line, int spec)
{
	char	*str;

	(void)spec;
	str = va_arg(ap, char *);
	if (line->space == ON && str == NULL)
	{
		line->space = OFF;
		ft_add_chr(&line->str, ft_chr_new(' '), line);
	}
	if (!str)
		str = NULL_STR;
	ft_add_str(str, line);
	return (JUMP);
}

void	ft_add_str(char *str, t_line *line)
{
	while (*str)
		ft_add_chr(&line->str, ft_chr_new(*(str++)), line);
}
