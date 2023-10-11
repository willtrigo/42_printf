/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:17:33 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 04:35:00 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_get_spec(const char *format, va_list ap, t_ln *ln);
static size_t	ft_mng_spec(const char *format, va_list ap, t_ln *ln);
static void		ft_print_ln(t_ln *ln);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_ln	ln;

	if (!format)
		return (-1);
	ln.str = NULL;
	ln.len = 0;
	va_start(ap, format);
	ft_get_spec(format, ap, &ln);
	va_end(ap);
	ft_print_ln(&ln);
	return (ln.len);
}

static void	ft_get_spec(const char *format, va_list ap, t_ln *ln)
{
	while (*format)
	{
		if (*format == '%')
			ft_mng_spec(++format, ap, ln);
		else if (*format)
			ft_add_c(&ln->str, ft_c_new(*format), ln);
		format++;
	}
}

static size_t	ft_mng_spec(const char *format, va_list ap, t_ln *ln)
{
	char	next_c;

	next_c = *(format + NEXT_BYTE);
	if (next_c == 'c')
		return (ft_cast_c(ap, ln));
	if (next_c == 's')
		return (ft_cast_str(ap, ln));
	if (next_c == 'p')
		return (ft_cast_hex_ptr(ap, ln, CHK_HEX_PTR));
	if (next_c == 'd' || next_c == 'i')
		return (ft_cast_int(ap, ln, CHK_INT_D_I));
	if (next_c == 'u')
		return (ft_cast_int(ap, ln, CHK_INT_U));
	if (next_c == 'x')
		return (ft_cast_hex_lw_up(ap, ln, CHK_HEX_LW));
	if (next_c == 'X')
		return (ft_cast_hex_lw_up(ap, ln, CHK_HEX_UP));
	if (next_c == '%')
		ft_add_c(&ln->str, ft_c_new('%'), ln);
	return (JUMP_SPEC);
}

static void	ft_print_ln(t_ln *ln)
{
	t_ln_c	*ln_temp;
	char	*ln_new;
	size_t	i;

	ln_new = malloc(sizeof(char) * (ln->len + NULL_BYTE));
	if (!ln_new)
	{
		free(ln_new);
		return ;
	}
	i = 0;
	ln_temp = NULL;
	while (ln->str)
	{
		ln_temp = ln->str->next;
		ln_new[i++] = ln->str->c;
		free(ln->str);
		ln->str = ln_temp;
	}
	ln_new[i] = '\0';
	write(STDOUT_FILENO, ln_new, ln->len);
	free(ln_new);
}
