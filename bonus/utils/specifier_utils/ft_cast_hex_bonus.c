/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/11/03 07:57:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_cast_hex_lw_up_aux(t_line *line, t_hex_status *hex_status,
				const t_ulli hex, int spec);
static void	ft_get_hex(t_line *line, t_ulli hex,
				t_hex_status *hex_status, int spec);
static void	ft_add_hex(t_line *line, t_ulli hex,
				t_hex_status *hex_status, int spec);
void		ft_combination_add(t_line *line, char chr, int size);

void	ft_cast_hex_ptr(va_list ap, t_line *line, t_line *format, int spec)
{
	t_ulli			hex;
	t_hex_status	hex_status;

	hex = va_arg(ap, t_uli);
	hex_status.len = 2;
	hex_status.active = OFF;
	if (!hex)
	{
		hex_status.len = 5;
		ft_combination_hex_math(line, &hex_status);
		ft_combination_head_hex(line);
		ft_str_insert(NULL_PTR, line);
	}
	else
	{
		ft_get_hex(line, hex, &hex_status, spec);
		ft_combination_hex_math(line, &hex_status);
		ft_combination_head_hex(line);
		hex_status.len = 2;
		hex_status.active = ON;
		line->hash = ON;
		ft_add_hex(line, hex, &hex_status, CHK_HEX_LW);
	}
	ft_combination_tail_hex(line);
	ft_format_jump(format);
}

void	ft_cast_hex_lw_up(va_list ap, t_line *line, t_line *format, int spec)
{
	const t_ulli	hex = (t_ulli)va_arg(ap, t_ui);
	t_hex_status	hex_status;

	hex_status.len = 0;
	hex_status.active = OFF;
	if (!hex)
	{
		hex_status.len = 1;
		ft_combination_hex_math_null(line);
		hex_status.len = 0;
		ft_combination_head_hex(line);
		if (!((line->prec != FAIL) || (line->zero == ON)))
			ft_str_insert("0", line);
	}
	else
		ft_cast_hex_lw_up_aux(line, &hex_status, hex, spec);
	ft_combination_tail_hex(line);
	ft_format_jump(format);
}

static void	ft_cast_hex_lw_up_aux(t_line *line, t_hex_status *hex_status,
				const t_ulli hex, int spec)
{
	if (spec == CHK_HEX_LW)
		ft_get_hex(line, hex, hex_status, CHK_HEX_LW);
	else
		ft_get_hex(line, hex, hex_status, CHK_HEX_UP);
	ft_combination_hex_math(line, hex_status);
	hex_status->len = 0;
	ft_combination_head_hex(line);
	hex_status->active = ON;
	if (spec == CHK_HEX_LW)
		ft_add_hex(line, hex, hex_status, CHK_HEX_LW);
	else
		ft_add_hex(line, hex, hex_status, CHK_HEX_UP);
}

static void	ft_get_hex(t_line *line, t_ulli hex,
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

static void	ft_add_hex(t_line *line, t_ulli hex,
				t_hex_status *hex_status, int spec)
{
	if (line->hash == ON && spec == CHK_HEX_LW)
		ft_str_insert("0x", line);
	else if (line->hash == ON && spec == CHK_HEX_UP)
		ft_str_insert("0X", line);
	if (spec == CHK_HEX_LW)
		ft_get_hex(line, hex, hex_status, CHK_HEX_LW);
	else
		ft_get_hex(line, hex, hex_status, CHK_HEX_UP);
}
