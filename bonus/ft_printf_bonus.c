/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/15 05:41:48 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_line	line;

	if (!format)
		return (FAIL);
	line = ft_line_init();
	va_start(ap, format);
	ft_get_spec(format, ap, &line, DEFAULT_INIT);
	va_end(ap);
	ft_print_line(&line);
	return (line.len);
}
