/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 09:19:09 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/04 23:43:17 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

void	ft_parse_width(t_line *format, t_line *line)
{
	line->width = ON;
	if (format->str->chr == '0')
	{
		ft_format_jump(format);
		ft_parse_zero(format, line);
		return ;
	}
	while (format->str)
	{
		if (ft_check_spec(format, DEFAULT_INIT) == ON)
			break ;
		else if (format->str->chr == '.')
			ft_parse_precision(format, line);
		else if (format->str->chr == '-')
			ft_parse_minus(format, line);
		else if (format->str->chr >= '1' && format->str->chr <= '9')
			line->width = ft_parse_nbr(format, DEFAULT_INIT);
	}
}
