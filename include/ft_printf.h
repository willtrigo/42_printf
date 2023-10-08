/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:42:43 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/08 00:13:04 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define NEXT_BYTE 1
# define NULL_BYTE 1
# define JUMP_SPECIFIER 1
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"
# define CHECK_HEX_PTR 1
# define CHECK_HEX_LW 2
# define CHECK_HEX_UP 3
# define CHECK_INT_D_I 1
# define CHECK_INT_U 2
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"

typedef struct s_line_char	t_line_char;
struct s_line_char
{
	char		c;
	t_line_char	*next;
};

typedef struct s_line		t_line;
struct s_line
{
	t_line_char	*str;
	size_t		len;
};

int			ft_printf(const char *format, ...);
void		ft_add_char(t_line_char **line_char, t_line_char *char_new);
t_line_char	*ft_char_new(char c);
char		*free_line(t_line_char *line_char);
size_t		ft_cast_char(va_list ap, t_line *line);
size_t		ft_cast_str(va_list ap, t_line *line);
void		ft_add_str(char *str, t_line *line);
size_t		ft_cast_hex_ptr(va_list ap, t_line *line, int speficier);
size_t		ft_cast_hex_lw_up(va_list ap, t_line *line, int speficier);
size_t		ft_cast_int(va_list ap, t_line *line, int speficier);

#endif
