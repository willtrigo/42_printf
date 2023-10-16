/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 04:50:00 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/15 22:29:41 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

int	ft_str_len(const char *str);

size_t	ft_cast_str(va_list ap, t_line *line, int spec)
{
	int			str_len;
	const char	*str = va_arg(ap, char *);

	(void)spec;
	if (!str)
		str = NULL_STR;
	str_len = ft_str_len(str);
	ft_str_add((char *)str, line);
	if (line->width >= ON && line->minus >= ON)
		while ((line->width-- - 1 - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->width >= ON && line->minus >= OFF)
		while ((line->width-- - 1 - str_len) > FAIL)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	return (JUMP);
}

void	ft_str_add(char *str, t_line *line)
{
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
