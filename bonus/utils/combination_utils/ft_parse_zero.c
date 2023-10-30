/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:25:23 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/30 07:13:44 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_parse_zero(t_line *format, t_line *line)
{
	t_line_chr	*format_next;

	format_next = format->str->next;
	line->zero = ON;
	while (format->str->chr == '0')
		ft_format_jump(format);
	if (ft_check_spec(format, DEFAULT_INIT) == ON)
		return ;
	while (format->str)
	{
		if (ft_check_spec(format, DEFAULT_INIT) == ON)
			break ;
		if (format->str->chr == '.')
			ft_parse_precision(format, line);
		if (format->str->chr == '-')
			ft_parse_minus(format, line);
		if (format->str->chr >= '1' && format->str->chr <= '9')
			ft_parse_width(format, line);
	}
}
