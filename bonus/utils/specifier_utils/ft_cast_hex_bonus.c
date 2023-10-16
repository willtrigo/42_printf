/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/16 10:44:00 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_get_hex(t_line *line, t_uli hex, int len, int spec);

size_t	ft_cast_hex_ptr(va_list ap, t_line *line, int spec)
{
	const t_uli	hex = va_arg(ap, t_uli);

	if (spec == CHK_HEX_PTR)
	{
		if (!hex)
			ft_str_add(NULL_PTR, line);
		else
		{
			ft_str_add("0x", line);
			ft_get_hex(line, hex, 0, spec);
		}
	}
	if (line->width >= ON)
		while (line->width-- - ft_get_width_int((t_ulli)hex) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	return (JUMP);
}

size_t	ft_cast_hex_lw_up(va_list ap, t_line *line, int spec)
{
	const t_ulli	hex = (t_ulli)va_arg(ap, t_ui);

	if (!hex)
		ft_str_add("0", line);
	else
	{
		if (line->hash == ON && spec == CHK_HEX_LW)
			ft_str_add("0x", line);
		else if (line->hash == ON && spec == CHK_HEX_UP)
			ft_str_add("0X", line);
		if (spec == CHK_HEX_LW)
			ft_get_hex(line, hex, 0, CHK_HEX_LW);
		else
			ft_get_hex(line, hex, 0, CHK_HEX_UP);
	}
	if (line->width >= ON)
		while ((line->width-- - 10) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	return (JUMP);
}

static void	ft_get_hex(t_line *line, t_uli hex, int len, int spec)
{
	if (spec == CHK_HEX_UP)
	{
		if (hex >= 16)
			ft_get_hex(line, hex / 16, ++len, CHK_HEX_UP);
		ft_chr_add(&line->str, ft_chr_new(HEX_UP[hex % 16]), line);
	}
	else
	{
		if (hex >= 16)
			ft_get_hex(line, hex / 16, ++len, CHK_HEX_LW);
		ft_chr_add(&line->str, ft_chr_new(HEX_LW[hex % 16]), line);
	}
}
