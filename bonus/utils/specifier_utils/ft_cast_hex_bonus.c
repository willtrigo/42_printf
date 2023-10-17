/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/17 16:52:37 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_get_hex(t_line *line, t_uli hex, int len, int spec);
static void	ft_flag_add_hex(t_line *line, int hex_len);
static int	ft_get_hex_len(const t_uli hex);

size_t	ft_cast_hex_ptr(va_list ap, t_line *line, int spec)
{
	t_uli	hex;

	hex = va_arg(ap, t_uli);
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
	if (line->width >= ON && line->minus == OFF)
		while (line->width-- - 1 - ft_get_width_int_len((t_ulli)hex) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->minus >= ON && ft_get_width_int_len((t_ulli)hex) == 10)
		while ((line->width-- - ft_get_width_int_len((t_ulli)hex)) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	return (JUMP);
}

size_t	ft_cast_hex_lw_up(va_list ap, t_line *line, int spec)
{
	int				hex_len;
	const t_ulli	hex = (t_ulli)va_arg(ap, t_ui);

	hex_len = ft_get_hex_len(hex);
	if (line->width >= ON && line->zero >= ON)
		while ((line->width-- - hex_len) > OFF)
			ft_chr_add(&line->str, ft_chr_new('0'), line);
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
	ft_flag_add_hex(line, hex_len);
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

static void	ft_flag_add_hex(t_line *line, int hex_len)
{
	if (line->width >= ON && line->minus == OFF)
		while (line->width-- - 1 - hex_len > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
	if (line->minus >= ON)
		while ((line->width-- - hex_len) > OFF)
			ft_chr_add(&line->str, ft_chr_new(' '), line);
}

static int	ft_get_hex_len(const t_uli hex)
{
	int	hex_len;

	hex_len = 1;
	if (hex >= 16)
		hex_len = ft_get_width_int_len(hex);
	if (hex_len == 10)
		hex_len = 8;
	return (hex_len);
}
