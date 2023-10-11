/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 23:13:52 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 04:35:50 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_add_c(t_ln_c **ln_c, t_ln_c *c_new, t_ln *ln)
{
	t_ln_c	*ln_temp;

	if (c_new)
	{
		if (!*ln_c)
			*ln_c = c_new;
		else
		{
			ln_temp = *ln_c;
			while (ln_temp->next)
				ln_temp = ln_temp->next;
			ln_temp->next = c_new;
		}
	}
	ln->len++;
}

t_ln_c	*ft_c_new(char c)
{
	t_ln_c	*c_new;

	c_new = malloc(sizeof(t_ln_c));
	if (!c_new)
	{
		free(c_new);
		return (NULL);
	}
	c_new->c = c;
	c_new->next = NULL;
	return (c_new);
}

char	*free_ln(t_ln_c *ln_c)
{
	t_ln_c	*ln_c_temp;

	ln_c_temp = ln_c;
	while (ln_c_temp)
	{
		ln_c_temp = ln_c_temp->next;
		free(ln_c);
		ln_c = ln_c_temp;
	}
	ln_c_temp = NULL;
	return (NULL);
}
