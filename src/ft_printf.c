/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/12 15:16:20 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
	line.len = 0;
	va_start(ap, format);
	ft_get_spec(format, ap, &line);
	va_end(ap);
	ft_print_line(&line);
	return (line.len);
}

static void	ft_get_spec(const char *format, va_list ap, t_line *line)
{
	while (*format)
	{
		if (*format == '%')
			ft_parse_spec(++format, ap, line);
		else
			ft_add_chr(&line->str, ft_chr_new(*format), line);
		format++;
	}
}

static size_t	ft_parse_spec(const char *format, va_list ap, t_line *line)
{
	const char	next_chr = *format;

	if (next_chr == 'c')
		return (ft_cast_chr(ap, line));
	if (next_chr == 's')
		return (ft_cast_str(ap, line));
	if (next_chr == 'p')
		return (ft_cast_hex_ptr(ap, line, CHK_HEX_PTR));
	if (next_chr == 'd' || next_chr == 'i')
		return (ft_cast_int(ap, line, CHK_INT_D_I));
	if (next_chr == 'u')
		return (ft_cast_int(ap, line, CHK_INT_U));
	if (next_chr == 'x')
		return (ft_cast_hex_lw_up(ap, line, CHK_HEX_LW));
	if (next_chr == 'X')
		return (ft_cast_hex_lw_up(ap, line, CHK_HEX_UP));
	if (next_chr == '%')
		return (ft_cast_per(ap, line, OFF));
	return (JUMP_SPEC);
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
