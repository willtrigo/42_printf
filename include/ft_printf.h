/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:42:43 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/12 15:00:55 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FAIL -1
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
# define ON 1
# define OFF 0

typedef unsigned long int		t_uli;
typedef unsigned long long int	t_ulli;
typedef unsigned int			t_ui;
typedef long int				t_li;

typedef struct s_line_chr		t_line_chr;
struct s_line_chr
{
	char		chr;
	t_line_chr	*next;
};

typedef struct s_line			t_line;
struct s_line
{
	t_line_chr	*str;
	size_t		len;
};

int			ft_printf(const char *format, ...);
void		ft_add_chr(t_line_chr **line_chr,
				t_line_chr *chr_new, t_line *line);
t_line_chr	*ft_chr_new(char c);
char		*free_line(t_line_chr *line_chr);
size_t		ft_cast_chr(va_list ap, t_line *line);
size_t		ft_cast_str(va_list ap, t_line *line);
void		ft_add_str(char *str, t_line *line);
size_t		ft_cast_hex_ptr(va_list ap, t_line *line, int spec);
size_t		ft_cast_hex_lw_up(va_list ap, t_line *line, int spec);
size_t		ft_cast_int(va_list ap, t_line *line, int spec);
size_t		ft_cast_per(va_list ap, t_line *line, int spec);

#endif
