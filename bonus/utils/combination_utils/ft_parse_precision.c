/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:15:19 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/29 06:30:19 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static int	ft_precision_without_nbr(t_line *format, t_line *line);

void	ft_parse_precision(t_line *format, t_line *line)
{
	line->prec = FAIL;
	while (format->str->chr == '.')
		ft_format_jump(format);
	if (ft_precision_without_nbr(format, line) == ON)
		return ;
	if (ft_check_spec(format, DEFAULT_INIT) == ON)
		return ;
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
		if (format->str->chr == '-')
			ft_parse_minus(format, line);
		if (format->str->chr >= '1' && format->str->chr <= '9')
			line->prec = ft_parse_nbr(format, DEFAULT_INIT);
	}
}

static int	ft_precision_without_nbr(t_line *format, t_line *line)
{
	if (format->str->chr == 's' || format->str->chr == 'x'
		|| format->str->chr == 'X')
	{
		line->prec = FAIL;
		return (ON);
	}
	return (OFF);
}
