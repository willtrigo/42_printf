/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 05:59:50 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/21 00:59:00 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static size_t				ft_parse_spec(const char *format,
								va_list ap, t_line *line);
static int					ft_spec_len(const t_parse_spec_struct *parse_spec,
								int len);
static t_parse_spec_struct	ft_parse_spec_init(void);

void	ft_get_spec(const char *format, va_list ap, t_line *line)
{
	while (*format)
	{
		if (*format == '%')
			ft_parse_spec(++format, ap, line);
		else
			ft_chr_add(&line->str, ft_chr_new(*format), line);
		format++;
	}
}

static size_t	ft_parse_spec(const char *format, va_list ap, t_line *line)
{
	const t_parse_spec_struct	parse_spec = ft_parse_spec_init();
	int							spec_len;

	spec_len = ft_spec_len(&parse_spec, DEFAULT_INIT);
	while (--spec_len > FAIL)
		if (*format == parse_spec.spec[spec_len].chr)
			parse_spec.spec[spec_len].cast_fn(ap, line,
				parse_spec.spec[spec_len].spec);
	return (JUMP);
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

static int	ft_spec_len(const t_parse_spec_struct *parse_spec, int len)
{
	while (parse_spec->spec[len].chr)
		len++;
	return (len);
}
