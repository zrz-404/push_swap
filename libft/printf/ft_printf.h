/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:55:24 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/14 17:41:01 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Buffer def -> 4096 bytes
# define BUF_SIZE		4096
// Useful strings
# define FLAGS 			"+ 0-#"
# define NUMBERS		"0123456789"
# define SPECIFIERS		"cspdiuxX%"
# define LO_SYM			"0123456789abcdef"
# define UP_SYM			"0123456789ABCDEF"

# include "../libft.h" //libft
# include <stdarg.h> // variadic funcs
# include <stdio.h> // real printf
# include <stdlib.h> // malloc free
# include <unistd.h> // write func
# include <stdbool.h> //booleans for readability

//symbolic error representation
typedef enum error
{
	OK = 0,
	MALLOC_ERROR = -404,
	PARSE_ERROR = -42
}	t_error;

//
typedef union int_u
{
	unsigned long	uint64;
	long			int64;
}	t_uint;

// integer base
typedef enum base
{
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16
}	t_base;

//	all the bools	[+-' '0#][width][.precision]
typedef struct s_format
{
	//parsing
	//flags
	bool	plus;
	bool	left;
	bool	space;
	bool	zero;
	//specifiers	"csdixXpu"
	char	spec;
	//width + precision
	int		width;
	int		precision;

	int		star;
	int		hash;

	char	buf_tmp[64];
	int		nbr_len;
	bool	upper_case;
	t_base	base;
	// padding = p
	int		p_spaces;
	int		p_zeros;
	bool	signed_value;
	bool	is_negative;
	bool	is_converted;
}	t_format;

//	using typedef we can make the code cleaner later on

typedef struct s_data
{
	// pointer copy to format
	const char	*s;
	// va_list ->va_arg(ap, int);
	va_list		ap;
	//chars written
	int			c_written;
	// buffer
	char		*buf;
	int			b_index;
	// All the bools [=-' '0#][width][.precision]
	t_format	fmt;
}	t_data;

/*					### PROTOTYPES ###					*/
int		ft_printf(const char *format, ...);
// utilities
bool	in(const char *s, char c);
// Parsing
int		parse_format(t_data *data);
// Buffer
void	write_buf(t_data *data, char c);
void	flush_buf(t_data *data);
void	ft_pchar_buf_n(char c, int precision, t_data *data);
void	ft_pstr_buf_n(char *s, int precision, t_data *data);
void	itoa_buf(t_data *data, t_uint int_v);
// rendering
void	ft_pchar(t_data *data, int c);
void	ft_pstr(t_data *data, char *s);
void	print_int(t_data *data, t_uint int_v);
void	set_p_spaces(t_data *data);
void	set_p_zeros(t_data *data);
void	ft_print_p(unsigned long int n, t_data *data);
void	ft_paddr(t_data *data, void *ptr);

#endif

/*
t_format	ft_format_init(void);
t_format	ft_flag_left(t_format flags);
t_format	ft_flag_digit(char c, t_format flags);
t_format	ft_flag_width(va_list args, t_format flags);
int			ft_flag_precision(const char *str, int pos, va_list args,
				t_format *flags);

						 ### PRINTF ###
int			ft_printf(const char *format, ...);
int			ft_print_arg(char type, va_list args, t_format flags);

					### SPECIFIERS ###
// c
int			ft_print_char(char c, t_format flags);
int			ft_print_c(char c);
// s (null term string)
int			ft_print_str(const char *str, t_format flags);
int			ft_print_s(const char *str);
int			ft_print_s_pre(const char *str, int precision);
int			ft_print_sign_pre(int n, t_format *flags);
// i, d (signed int)
int			ft_print_int(int n, t_format flags);
int			ft_print_integer(char *nstr, int n, t_format flags);
int			ft_print_i(char *nstr, t_format flags);
// u (decimal unsigned int)
int			ft_print_unsigned(unsigned int n, t_format flags);
int			ft_print_u(char *nstr, t_format flags);
int			ft_print_u_int(char *nstr, t_format flags);
// x, X (unsigned int hexadecimal)
int			ft_print_hex(unsigned int n, int is_upper, t_format flags);
int			ft_print_x(char *nstr, int n, int is_upper, t_format flags);
int			ft_print_hexa(char *nstr, int n, int is_upper, t_format flags);
// p (prints address of a pointer or ar. displayed in hex)
int			ft_print_ptr(unsigned long int n, t_format flags);
int			ft_print_p(unsigned long int n);
void		ft_print_adr(unsigned long int n);

					 ### HELPERS ###
char		*ft_printf_itoa(long nb);
char		*ft_printf_utoa(unsigned int nb);
char		*ft_printf_xtoa(unsigned long int nb, int is_upper);
int			ft_unint_len(unsigned int n);
int			ft_hex_len(unsigned int n);
int			ft_ptr_len(unsigned long int n);
int			ft_istype(int c);
int			ft_isspec(int c);
int			ft_isflag(int c);

					 ### f_FLAG ###
int			ft_pad_w(int total_w, int size, int zero);
*/
