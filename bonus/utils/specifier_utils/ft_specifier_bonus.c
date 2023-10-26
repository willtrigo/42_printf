/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:59:50 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:24:19 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static t_parse_spec_struct	ft_parse_spec_init(void);
static void					ft_line_reset(t_line *line);

void	ft_get_spec(const char *format, va_list ap, t_line *line, size_t jump)
{
	while (*format)
	{
		if (*format == '%')
		{
			jump = 0;
			jump += ft_parse_spec(++format, ap, line);
			format += jump;
			ft_line_reset(line);
		}
		else
			ft_chr_add(&line->str, ft_chr_new(*format), line);
		format++;
	}
}

size_t	ft_parse_spec(const char *format, va_list ap, t_line *line)
{
	const t_parse_spec_struct	parse_spec = ft_parse_spec_init();
	size_t						jump;
	int							spec_len;

	jump = 0;
	spec_len = SPEC_SIZE;
	jump = ft_parse_combination(format, line, DEFAULT_INIT);
	while (--spec_len > FAIL)
		if (*(format + jump) == parse_spec.spec[spec_len].chr)
			parse_spec.spec[spec_len].cast_fn(ap, line,
				parse_spec.spec[spec_len].spec);
	return (jump);
}

int	ft_check_spec(const char *format, int i)
{
	ssize_t	spec_i;

	spec_i = 0;
	while (SPEC[spec_i])
		if (format[i] == SPEC[spec_i++])
			return (ON);
	return (OFF);
}

static t_parse_spec_struct	ft_parse_spec_init(void)
{
	return ((t_parse_spec_struct){.spec = {
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
		}});
}

static void	ft_line_reset(t_line *line)
{
	line->minus = OFF;
	line->plus = OFF;
	line->hash = OFF;
	line->space = OFF;
	line->zero = OFF;
	line->width = OFF;
	line->prec = OFF;
}
