/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/20 05:30:39 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_get_hex(t_line *line, t_uli hex,
				t_hex_status *hex_status, int spec);
static void	ft_flag_add_hex(t_line *line,
				t_hex_status *hex_status, t_ulli hex, int spec);

size_t	ft_cast_hex_ptr(va_list ap, t_line *line, int spec)
{
	t_uli			hex;
	t_hex_status	hex_status;

	hex = va_arg(ap, t_uli);
	hex_status.len = 0;
	hex_status.active = ON;
	if (spec == CHK_HEX_PTR)
	{
		if (!hex)
			ft_str_add(NULL_PTR, line);
		else
		{
			ft_str_add("0x", line);
			ft_get_hex(line, hex, &hex_status, spec);
			hex_status.len += 2;
		}
	}
	if (line->width >= ON && line->minus == OFF)
		while ((line->width-- - hex_status.len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->minus >= ON && hex_status.len == 10)
		while ((line->width-- - hex_status.len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	return (JUMP);
}

size_t	ft_cast_hex_lw_up(va_list ap, t_line *line, int spec)
{
	const t_ulli	hex = (t_ulli)va_arg(ap, t_ui);
	t_hex_status	hex_status;

	hex_status.len = 0;
	hex_status.active = OFF;
	if (spec == CHK_HEX_LW)
		ft_get_hex(line, hex, &hex_status, CHK_HEX_LW);
	else
		ft_get_hex(line, hex, &hex_status, CHK_HEX_UP);
	if ((line->width >= ON && line->zero >= ON) || (line->width
			>= ON && line->prec >= ON))
	{
		if (line->prec >= ON && (hex_status.len == line->width))
			line->width = 0;
		while ((line->width-- - hex_status.len) > OFF)
			ft_chr_add(&line->str, ft_chr_new('0'), line);
		if (hex == 0 && line->prec >= ON)
			ft_chr_add(&line->str, ft_chr_new('0'), line);
	}
	hex_status.active = ON;
	hex_status.len = 0;
	ft_flag_add_hex(line, &hex_status, hex, spec);
	return (JUMP);
}

static void	ft_get_hex(t_line *line, t_uli hex,
				t_hex_status *hex_status, int spec)
{
	hex_status->len++;
	if (spec == CHK_HEX_UP)
	{
		if (hex >= 16)
			ft_get_hex(line, hex / 16, hex_status, CHK_HEX_UP);
		if (hex_status->active == ON)
			ft_chr_add(&line->str, ft_chr_new(HEX_UP[hex % 16]), line);
	}
	else
	{
		if (hex >= 16)
			ft_get_hex(line, hex / 16, hex_status, CHK_HEX_LW);
		if (hex_status->active == ON)
			ft_chr_add(&line->str, ft_chr_new(HEX_LW[hex % 16]), line);
	}
}

static void	ft_flag_add_hex(t_line *line,
				t_hex_status *hex_status, t_ulli hex, int spec)
{
	if (!hex)
		ft_str_add("0", line);
	else
	{
		if (line->hash == ON && spec == CHK_HEX_LW)
			ft_str_add("0x", line);
		else if (line->hash == ON && spec == CHK_HEX_UP)
			ft_str_add("0X", line);
		if (spec == CHK_HEX_LW)
			ft_get_hex(line, hex, hex_status, CHK_HEX_LW);
		else
			ft_get_hex(line, hex, hex_status, CHK_HEX_UP);
	}
	if (line->width >= ON && line->minus == OFF)
		while (line->width-- - 1 - hex_status->len > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (hex == 0)
		line->minus = OFF;
	if (line->minus >= ON)
		while ((line->width-- - hex_status->len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}
