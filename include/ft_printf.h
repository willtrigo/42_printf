/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:42:43 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/11 07:53:29 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define NEXT_BYTE 1
# define NULL_BYTE 1
# define JUMP_SPEC 1
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"
# define CHK_HEX_PTR 1
# define CHK_HEX_LW 2
# define CHK_HEX_UP 3
# define CHK_INT_D_I 1
# define CHK_INT_U 2
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct s_ln_c	t_ln_c;
struct s_ln_c
{
	char	c;
	t_ln_c	*next;
};

typedef struct s_ln		t_ln;
struct s_ln
{
	t_ln_c	*str;
	size_t	len;
};

int		ft_printf(const char *format, ...);
void	ft_add_c(t_ln_c **ln_c, t_ln_c *c_new, t_ln *ln);
t_ln_c	*ft_c_new(char c);
char	*free_ln(t_ln_c *ln_c);
size_t	ft_cast_c(va_list ap, t_ln *ln);
size_t	ft_cast_str(va_list ap, t_ln *ln);
void	ft_add_str(char *str, t_ln *ln);
size_t	ft_cast_hex_ptr(va_list ap, t_ln *ln, int spec);
size_t	ft_cast_hex_lw_up(va_list ap, t_ln *ln, int spec);
size_t	ft_cast_int(va_list ap, t_ln *ln, int spec);

#endif
