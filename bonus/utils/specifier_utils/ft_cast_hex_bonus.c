/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_hex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/09 05:27:43 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

static void	ft_get_hex(t_line *line,
				unsigned long int ptr, int len, int specifier);

size_t	ft_cast_hex_ptr(va_list ap, t_line *line, int speficier)
{
	unsigned long int	hex;

	hex = va_arg(ap, unsigned long int);
	if (speficier == CHECK_HEX_PTR)
	{
		if (!hex)
			ft_add_str(NULL_PTR, line);
		else
		{
			ft_add_str("0x", line);
			ft_get_hex(line, hex, 0, speficier);
		}
	}
	return (JUMP_SPECIFIER);
}

size_t	ft_cast_hex_lw_up(va_list ap, t_line *line, int speficier)
{
	unsigned int	hex;

	hex = va_arg(ap, unsigned int);
	if (hex == '0')
		ft_add_str(NULL_STR, line);
	else
	{
		if (speficier == CHECK_HEX_LW)
			ft_get_hex(line, hex, 0, CHECK_HEX_LW);
		else
			ft_get_hex(line, hex, 0, CHECK_HEX_UP);
	}
	return (JUMP_SPECIFIER);
}

static void	ft_get_hex(t_line *line,
				unsigned long int ptr, int len, int specifier)
{
	if (specifier == CHECK_HEX_UP)
	{
		if (ptr >= 16)
			ft_get_hex(line, ptr / 16, ++len, CHECK_HEX_UP);
		ft_add_char(&line->str, ft_char_new(HEX_UP[ptr % 16]), line);
	}
	else
	{
		if (ptr >= 16)
			ft_get_hex(line, ptr / 16, ++len, CHECK_HEX_LW);
		ft_add_char(&line->str, ft_char_new(HEX_LW[ptr % 16]), line);
	}
}
