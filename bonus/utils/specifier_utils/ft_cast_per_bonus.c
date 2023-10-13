/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_per_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:37:36 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/13 19:16:06 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_per(va_list ap, t_line *line, int spec)
{
	(void)ap;
	(void)spec;
	ft_add_chr(&line->str, ft_chr_new('%'), line);
	return (JUMP);
}
