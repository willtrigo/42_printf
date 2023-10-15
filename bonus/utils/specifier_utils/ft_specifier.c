/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:59:50 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/15 05:32:27 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static int	ft_spec_len(const t_parse_spec *parse_spec);

void	ft_get_spec(const char *format, va_list ap, t_line *line, size_t jump)
{
	while (*format)
	{
		if (*format == '%')
		{
			jump = 0;
			jump += ft_parse_spec(++format, ap, line);
			format += jump;
		}
		else
			ft_chr_add(&line->str, ft_chr_new(*format), line);
		format++;
	}
}

size_t	ft_parse_spec(const char *format, va_list ap, t_line *line)
{
	const t_parse_spec	parse_spec[] = {
	{'c', &ft_cast_chr, OFF},
	{'s', &ft_cast_str, OFF},
	{'p', &ft_cast_hex_ptr, CHK_HEX_PTR},
	{'d', &ft_cast_int, CHK_INT_D_I},
	{'i', &ft_cast_int, CHK_INT_D_I},
	{'u', &ft_cast_int, CHK_INT_U},
	{'x', &ft_cast_hex_lw_up, CHK_HEX_LW},
	{'X', &ft_cast_hex_lw_up, CHK_HEX_UP},
	{'%', &ft_cast_per, OFF},
	{'\0', NULL, OFF}
	};
	size_t				jump;
	int					spec_len;

	jump = 0;
	spec_len = ft_spec_len(parse_spec);
	jump = ft_parse_combination(format, line, DEFAULT_INIT);
	while (--spec_len > FAIL)
		if (*(format + jump) == parse_spec[spec_len].chr)
			parse_spec[spec_len].cast_fn(ap, line, parse_spec[spec_len].spec);
	return (jump);
}

static int	ft_spec_len(const t_parse_spec *parse_spec)
{
	int	len;

	len = 0;
	while (parse_spec[len].chr)
		len++;
	return (len);
}
