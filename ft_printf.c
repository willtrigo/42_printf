/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/02 04:52:23 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_get_flags(const char *format, va_list ap, t_line *line);

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_line	line;

	line.str = NULL;
	line.len = 0;
	va_start(ap, format);
	ft_get_flags(format, ap, &line);
	va_end(ap);
	return (line.len);
}

static void	ft_get_flags(const char *format, va_list ap, t_line *line)
{
	(void)ap;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
		}
		else
		{
			line->len += write(1, format, 1);
			format++;
		}
	}
}
