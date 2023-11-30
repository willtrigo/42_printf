/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:42:43 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/28 00:36:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FAIL -1
# define NULL_BYTE 1
# define NULL_PTR "(nil)"
# define NULL_STR "(null)"
# define CHK_HEX_PTR 1
# define CHK_HEX_LW 2
# define CHK_HEX_UP 3
# define CHK_INT_D_I 1
# define CHK_INT_U 2
# define HEX_LW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define HEX_BASE 16
# define ON 1
# define OFF 0
# define DEFAULT_INIT 0
# define SPEC_SIZE 10

typedef unsigned int				t_ui;
typedef unsigned long int			t_uli;
typedef unsigned long long int		t_ulli;
typedef long long int				t_lli;

typedef struct s_line_chr			t_line_chr;
struct s_line_chr
{
	char		chr;
	t_line_chr	*next;
};

typedef struct s_line				t_line;
struct s_line
{
	t_line_chr	*str;
	ssize_t		len;
};

typedef void						(*t_cast_function)(va_list,
										t_line *, t_line *, int);

typedef struct s_parse_spec			t_parse_spec;
struct s_parse_spec
{
	char			chr;
	t_cast_function	cast_fn;
	int				spec;
};

typedef struct s_parse_spec_struct	t_parse_spec_struct;
struct s_parse_spec_struct
{
	t_parse_spec	spec[SPEC_SIZE];
};

int			ft_printf(const char *format, ...);
void		ft_get_spec(t_line *format, va_list ap, t_line *line);
void		ft_cast_chr(va_list ap, t_line *line, t_line *format, int spec);
void		ft_cast_str(va_list ap, t_line *line, t_line *format, int spec);
void		ft_str_add(char *str, t_line *line);
void		ft_cast_hex_ptr(va_list ap, t_line *line, t_line *format, int spec);
void		ft_cast_hex_lw_up(va_list ap, t_line *line,
				t_line *format, int spec);
void		ft_cast_int(va_list ap, t_line *line, t_line *format, int spec);
void		ft_cast_per(va_list ap, t_line *line, t_line *format, int spec);
t_line		ft_line_init(void);
void		ft_chr_add(t_line_chr **line_chr,
				t_line_chr *chr_new, t_line *line);
t_line_chr	*ft_chr_new(char c);
void		ft_print_line(t_line *line);
void		ft_format_jump(t_line *format);

#endif
