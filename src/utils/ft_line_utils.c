/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:13:52 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/09 05:11:29 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_add_char(t_line_char **line_char,
			t_line_char *char_new, t_line *line)
{
	t_line_char	*line_temp;

	if (char_new)
	{
		if (!*line_char)
			*line_char = char_new;
		else
		{
			line_temp = *line_char;
			while (line_temp->next)
				line_temp = line_temp->next;
			line_temp->next = char_new;
		}
	}
	line->len++;
}

t_line_char	*ft_char_new(char c)
{
	t_line_char	*char_new;

	char_new = malloc(sizeof(t_line_char));
	if (!char_new)
	{
		free(char_new);
		return (NULL);
	}
	char_new->c = c;
	char_new->next = NULL;
	return (char_new);
}

char	*free_line(t_line_char *line_char)
{
	t_line_char	*line_char_temp;

	line_char_temp = line_char;
	while (line_char_temp)
	{
		line_char_temp = line_char_temp->next;
		free(line_char);
		line_char = line_char_temp;
	}
	line_char_temp = NULL;
	return (NULL);
}
