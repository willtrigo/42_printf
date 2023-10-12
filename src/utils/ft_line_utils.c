/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:13:52 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/12 09:33:21 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_add_chr(t_line_chr **line_chr, t_line_chr *chr_new, t_line *line)
{
	t_line_chr	*line_temp;

	if (chr_new)
	{
		if (!*line_chr)
			*line_chr = chr_new;
		else
		{
			line_temp = *line_chr;
			while (line_temp->next)
				line_temp = line_temp->next;
			line_temp->next = chr_new;
		}
	}
	line->len++;
}

t_line_chr	*ft_chr_new(char chr)
{
	t_line_chr	*chr_new;

	chr_new = malloc(sizeof(t_line_chr));
	if (!chr_new)
	{
		free(chr_new);
		return (NULL);
	}
	chr_new->chr = chr;
	chr_new->next = NULL;
	return (chr_new);
}

char	*free_line(t_line_chr *line_chr)
{
	t_line_chr	*line_chr_temp;

	line_chr_temp = line_chr;
	while (line_chr_temp)
	{
		line_chr_temp = line_chr_temp->next;
		free(line_chr);
		line_chr = line_chr_temp;
	}
	line_chr_temp = NULL;
	return (NULL);
}
