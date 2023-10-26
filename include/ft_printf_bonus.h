/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:42:43 by dande-je          #+#    #+#             */
/*   Updated: 2023/10/24 04:20:13 by dande-je         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FAIL -1
# define NEXT_BYTE 1
# define NULL_BYTE 1
# define JUMP 1
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
# define SPEC "cspdiuxX%"
# define SPEC_PARSE "cspdiuxX"
# define DEFAULT_INIT 0
# define SPEC_SIZE 10

typedef unsigned int				t_ui;
typedef unsigned long int			t_uli;
typedef unsigned long long int		t_ulli;
typedef long int					t_li;
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
	t_line_chr		*str;
	ssize_t			len;
	int				minus;
	int				plus;
	int				hash;
	int				space;
	int				zero;
	int				width;
	int				prec;
};

typedef size_t						(*t_cast_function)(va_list, t_line *, int);

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

typedef struct s_hex_status			t_hex_status;
struct s_hex_status
{
	int				len;
	int				active;
};

int			ft_printf(const char *format, ...);
void		ft_get_spec(const char *format, va_list ap,
				t_line *line, size_t jump);
size_t		ft_parse_spec(const char *format, va_list ap, t_line *line);
int			ft_check_spec(const char *format, int i);
size_t		ft_parse_combination(const char *format, t_line *line, int spec_i);
int			ft_get_combination_nbr(const char *format, ssize_t format_init,
				ssize_t format_end, int nbr);
ssize_t		ft_parse_hash(const char *format, t_line *line);
ssize_t		ft_parse_plus(const char *format, t_line *line);
ssize_t		ft_parse_space(const char *format, t_line *line);
ssize_t		ft_parse_minus(const char *format, t_line *line);
ssize_t		ft_parse_width(const char *format, t_line *line);
int			ft_get_width(const char *format, ssize_t format_init,
				ssize_t format_end, int nbr);
t_lli		ft_get_width_int_len(t_lli nbr);
ssize_t		ft_parse_zero(const char *format, t_line *line);
ssize_t		ft_parse_precision(const char *format, t_line *line);
size_t		ft_cast_chr(va_list ap, t_line *line, int spec);
void		ft_combination_head_chr(t_line *line);
void		ft_combination_tail_chr(t_line *line);
size_t		ft_cast_str(va_list ap, t_line *line, int spec);
void		ft_str_add(char *str, t_line *line);
int			ft_str_len(const char *str);
void		ft_combination_head_str(t_line *line, char *str);
void		ft_combination_tail_str(t_line *line, int str_len);
size_t		ft_cast_hex_ptr(va_list ap, t_line *line, int spec);
size_t		ft_cast_hex_lw_up(va_list ap, t_line *line, int spec);
void		ft_combination_tail_hex_ptr(t_line *line, t_hex_status *hex_status);
void		ft_combination_head_hex_lw_up(t_line *line,
				t_hex_status *hex_status);
void		ft_combination_tail_hex_lw_up(t_line *line,
				t_ulli hex, t_hex_status *hex_status);
size_t		ft_cast_int(va_list ap, t_line *line, int spec);
void		ft_combination_head_nbr(t_line *line, t_lli nbr_len, int fn_nbr);
void		ft_combination_tail_nbr(t_line *line, t_lli nbr_len);
void		ft_combination_head_unbr(t_line *line, t_lli nbr_len, t_ui fn_nbr);
void		ft_combination_tail_unbr(t_line *line, t_lli nbr_len);
size_t		ft_cast_per(va_list ap, t_line *line, int spec);
t_line		ft_line_init(void);
void		ft_chr_add(t_line_chr **line_chr,
				t_line_chr *chr_new, t_line *line);
t_line_chr	*ft_chr_new(char chr);
void		ft_print_line(t_line *line);

#endif
