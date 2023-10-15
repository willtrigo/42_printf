/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_per_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 08:37:36 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/15 05:37:39 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf_bonus.h"

size_t	ft_cast_per(va_list ap, t_line *line, int spec)
{
	(void)ap;
	(void)spec;
	ft_chr_add(&line->str, ft_chr_new('%'), line);
	return (JUMP);
}
