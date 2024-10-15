/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:51:03 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/19 08:59:10 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	itoa_buf(t_data *data, t_uint int_v)
{
	t_uint	tmp;

	if (data->fmt.base < 2 || data->fmt.base > 16)
		return ;
	if (data->fmt.is_negative && !data->fmt.is_converted)
	{
		int_v.int64 = -(int_v.int64);
		data->fmt.is_converted = true;
		itoa_buf(data, int_v);
	}
	else if (int_v.uint64 < data->fmt.base)
	{
		if (data->fmt.upper_case)
			data->fmt.buf_tmp[data->fmt.nbr_len++] = UP_SYM[int_v.uint64];
		else
			data->fmt.buf_tmp[data->fmt.nbr_len++] = LO_SYM[int_v.uint64];
	}
	else
	{
		tmp.uint64 = int_v.uint64 / data->fmt.base;
		itoa_buf(data, tmp);
		tmp.uint64 = int_v.uint64 % data->fmt.base;
		itoa_buf(data, tmp);
	}
}

/* 
 write_buf gets called 2 times
 1 - when string is over
 2 - when buf is full [4k - input can be larger than 4k, it repeats]
*/
void	flush_buf(t_data *data)
{
	data->c_written += write(STDOUT_FILENO,
			data->buf,
			data->b_index);
	ft_memset(data->buf, 0, BUF_SIZE);
	data->b_index = 0;
}

/*
 * buffer receives and stores each character of the string
 * 
 *	"This is the answer: %d\n", 42
 *
 *		write_buf() -> 4k buffer 
 * 
 *		[This is the answer: 42] 
 *
 *		data->b_index == BUF_size -> checks if the buffer is full
 *		if so, refresh index and write *s in stdout
 *		if not, place input char into place indicated by the b_index
 * 
*/
void	write_buf(t_data *data, char c)
{
	if (data->b_index == BUF_SIZE)
	{
		flush_buf(data);
	}
	data->buf[data->b_index++] = c;
}

void	ft_pchar_buf_n(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		write_buf(data, c);
}

void	ft_pstr_buf_n(char *s, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision && *s)
		write_buf(data, *s++);
}
