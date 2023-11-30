/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/28 00:40:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static void	ft_get_hex(t_line *line, t_ulli hex, int len, int spec);

void	ft_cast_hex_ptr(va_list ap, t_line *line, t_line *format, int spec)
{
	const t_ulli	hex = va_arg(ap, t_uli);

	if (spec == CHK_HEX_PTR)
	{
		if (!hex)
			ft_str_add(NULL_PTR, line);
		else
		{
			ft_str_add("0x", line);
			ft_get_hex(line, hex, DEFAULT_INIT, spec);
		}
	}
	ft_format_jump(format);
}

void	ft_cast_hex_lw_up(va_list ap, t_line *line, t_line *format, int spec)
{
	const t_ulli	hex = (t_ulli)va_arg(ap, t_ui);

	if (!hex)
		ft_str_add("0", line);
	else
	{
		if (spec == CHK_HEX_LW)
			ft_get_hex(line, hex, DEFAULT_INIT, CHK_HEX_LW);
		else
			ft_get_hex(line, hex, DEFAULT_INIT, CHK_HEX_UP);
	}
	ft_format_jump(format);
}

static void	ft_get_hex(t_line *line, t_ulli hex, int len, int spec)
{
	if (spec == CHK_HEX_UP)
	{
		if (hex >= HEX_BASE)
			ft_get_hex(line, hex / HEX_BASE, ++len, CHK_HEX_UP);
		ft_chr_add(&line->str, ft_chr_new(HEX_UP[hex % HEX_BASE]), line);
	}
	else
	{
		if (hex >= HEX_BASE)
			ft_get_hex(line, hex / HEX_BASE, ++len, CHK_HEX_LW);
		ft_chr_add(&line->str, ft_chr_new(HEX_LW[hex % HEX_BASE]), line);
	}
}
