/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:17:51 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/05 20:55:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_parse_plus(t_line *format, t_line *line)
{
	t_line_chr	*format_next;

	format_next = format->str->next;
	line->plus = ON;
	if (format->str->chr == '0')
	{
		ft_format_jump(format);
		ft_parse_zero(format, line);
		return ;
	}
	while (format->str->chr == '+')
		ft_format_jump(format);
	if (ft_check_spec(format, DEFAULT_INIT) == ON)
		return ;
	while (format->str)
	{
		if (ft_check_spec(format, DEFAULT_INIT) == ON)
			break ;
		if (format->str->chr == '.')
			ft_parse_precision(format, line);
		if (format->str->chr >= '1' && format->str->chr <= '9')
			line->plus = ft_parse_nbr(format, DEFAULT_INIT);
	}
}
