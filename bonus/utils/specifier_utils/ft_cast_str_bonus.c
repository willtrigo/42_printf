/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 08:44:58 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_str(va_list ap, t_line *line, int spec)
{
	int		str_len;
	char	*str;

	(void)spec;
	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	else if (line->prec >= ON)
		ft_combination_head_str(line, str);
	str_len = ft_str_len((const char *)str);
	if (*str != '\0')
		ft_str_add(str, line);
	ft_combination_tail_str(line, str_len);
	return (JUMP);
}

void	ft_str_add(char *str, t_line *line)
{
	while (*(str + line->prec))
		ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
}

int	ft_str_len(const char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}
