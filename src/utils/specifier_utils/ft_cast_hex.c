/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 04:40:11 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static void	ft_get_hex(t_ln *ln, unsigned long int ptr, int len, int spec);

size_t	ft_cast_hex_ptr(va_list ap, t_ln *ln, int spec)
{
	unsigned long int	hex;

	hex = va_arg(ap, unsigned long int);
	if (spec == CHK_HEX_PTR)
	{
		if (!hex)
			ft_add_str(NULL_PTR, ln);
		else
		{
			ft_add_str("0x", ln);
			ft_get_hex(ln, hex, 0, spec);
		}
	}
	return (JUMP_SPEC);
}

size_t	ft_cast_hex_lw_up(va_list ap, t_ln *ln, int spec)
{
	unsigned int	hex;

	hex = va_arg(ap, unsigned int);
	if (hex == '0')
		ft_add_str(NULL_STR, ln);
	else
	{
		if (spec == CHK_HEX_LW)
			ft_get_hex(ln, hex, 0, CHK_HEX_LW);
		else
			ft_get_hex(ln, hex, 0, CHK_HEX_UP);
	}
	return (JUMP_SPEC);
}

static void	ft_get_hex(t_ln *ln, unsigned long int ptr, int len, int spec)
{
	if (spec == CHK_HEX_UP)
	{
		if (ptr >= 16)
			ft_get_hex(ln, ptr / 16, ++len, CHK_HEX_UP);
		ft_add_c(&ln->str, ft_c_new(HEX_UP[ptr % 16]), ln);
	}
	else
	{
		if (ptr >= 16)
			ft_get_hex(ln, ptr / 16, ++len, CHK_HEX_LW);
		ft_add_c(&ln->str, ft_c_new(HEX_LW[ptr % 16]), ln);
	}
}
