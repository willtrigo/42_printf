/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/10 04:39:23 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_get_specifier(const char *format, va_list ap, t_line *line);
static size_t	ft_manage_specifier(const char *format,
					va_list ap, t_line *line);
static void		ft_print_line(t_line *line);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_line	line;

	if (!format)
		return (-1);
	line.str = NULL;
	line.len = 0;
	va_start(ap, format);
	ft_get_specifier(format, ap, &line);
	va_end(ap);
	ft_print_line(&line);
	return (line.len);
}

static void	ft_get_specifier(const char *format, va_list ap, t_line *line)
{
	while (*format)
	{
		if (*format == '%')
			ft_manage_specifier(++format, ap, line);
		else if (*format)
			ft_add_char(&line->str, ft_char_new(*format), line);
		format++;
	}
}

static size_t	ft_manage_specifier(const char *format,
					va_list ap, t_line *line)
{
	char	next_char;

	next_char = *(format + NEXT_BYTE);
	if (next_char == 'c')
		return (ft_cast_char(ap, line));
	if (next_char == 's')
		return (ft_cast_str(ap, line));
	if (next_char == 'p')
		return (ft_cast_hex_ptr(ap, line, CHECK_HEX_PTR));
	if (next_char == 'd' || next_char == 'i')
		return (ft_cast_int(ap, line, CHECK_INT_D_I));
	if (next_char == 'u')
		return (ft_cast_int(ap, line, CHECK_INT_U));
	if (next_char == 'x')
		return (ft_cast_hex_lw_up(ap, line, CHECK_HEX_LW));
	if (next_char == 'X')
		return (ft_cast_hex_lw_up(ap, line, CHECK_HEX_UP));
	if (next_char == '%')
		ft_add_char(&line->str, ft_char_new('%'), line);
	return (JUMP_SPECIFIER);
}

static void	ft_print_line(t_line *line)
{
	t_line_char	*line_temp;
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
		line_new[i++] = line->str->c;
		free(line->str);
		line->str = line_temp;
	}
	line_new[i] = '\0';
	write(STDOUT_FILENO, line_new, line->len);
	free(line_new);
}
