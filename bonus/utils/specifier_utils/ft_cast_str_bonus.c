/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 01:45:05 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_str(va_list ap, t_line *line, int spec)
{
	char	*str;
	int		str_len;

	(void)spec;
	str = va_arg(ap, char *);
	if (!str)
		str = NULL_STR;
	str_len = ft_str_len((const char *)str);
	if (line->prec >= ON && line->prec <= str_len)
		line->minus -= line->prec - str_len;
	if (line->prec >= ON || line->width >= ON)
		ft_combination_head_str(line, str);
	if (*str != '\0' && line->prec != FAIL)
		ft_str_add(str, line);
	ft_combination_tail_str(line, str_len);
	return (JUMP);
}

void	ft_str_add(char *str, t_line *line)
{
	if (line->prec >= ON)
		while (line->prec--)
			ft_chr_add(&line->str, ft_chr_new(*(str++)), line);
	else
		while (*str)
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
