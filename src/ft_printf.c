/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/27 23:49:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_get_format(t_line *line_format, const char *format);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_line	line;
	t_line	line_format;

	if (!format)
		return (FAIL);
	line = ft_line_init();
	line_format = ft_line_init();
	va_start(ap, format);
	ft_get_format(&line_format, format);
	ft_get_spec(&line_format, ap, &line);
	va_end(ap);
	ft_print_line(&line);
	return (line.len);
}

static void	ft_get_format(t_line *line_format, const char *format)
{
	while (*format)
		ft_chr_add(&line_format->str, ft_chr_new(*(format++)), line_format);
}
