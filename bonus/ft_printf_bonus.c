/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/13 19:27:36 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

static void		ft_get_spec(const char *format, va_list ap, t_line *line);
static size_t	ft_parse_spec(const char *format, va_list ap, t_line *line);
static void		ft_print_line(t_line *line);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_line	line;

	if (!format)
		return (FAIL);
	line.str = NULL;
	line.len = OFF;
	line.minus = OFF;
	line.plus = OFF;
	line.hash = OFF;
	line.space = OFF;
	line.zero = OFF;
	line.width = OFF;
	line.prec = OFF;
	va_start(ap, format);
	ft_get_spec(format, ap, &line);
	va_end(ap);
	ft_print_line(&line);
	return (line.len);
}

static void	ft_get_spec(const char *format, va_list ap, t_line *line)
{
	size_t	jump;

	jump = 0;
	while (*format)
	{
		if (*format == '%')
		{
			jump = 0;
			jump += ft_parse_spec(++format, ap, line);
			format += jump;
		}
		else
			ft_add_chr(&line->str, ft_chr_new(*format), line);
		format++;
	}
}

static size_t	ft_parse_spec(const char *format, va_list ap, t_line *line)
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
	{'%', &ft_cast_per, OFF}
	};
	char				next_chr;
	size_t				jump;
	ssize_t				i;

	jump = 0;
	i = 9;
	jump = ft_parse_combination(format, line);
	next_chr = *(format + jump);
	while (--i > -1)
		if (next_chr == parse_spec[i].chr)
			parse_spec[i].cast_fn(ap, line, parse_spec[i].spec);
	return (jump);
}

static void	ft_print_line(t_line *line)
{
	t_line_chr	*line_temp;
	char		*line_new;
	size_t		i;

	line_new = malloc(sizeof(char) * (line->len + NULL_BYTE));
	if (!line_new)
	{
		free(line_new);
		return ;
	}
	i = 0;
	line_temp = NULL;
	while (line->str)
	{
		line_temp = line->str->next;
		line_new[i++] = line->str->chr;
		free(line->str);
		line->str = line_temp;
	}
	line_new[i] = '\0';
	write(STDOUT_FILENO, line_new, line->len);
	free(line_new);
}
