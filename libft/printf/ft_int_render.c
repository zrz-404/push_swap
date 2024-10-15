/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:51:03 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/22 15:55:16 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_0x(t_data *data)
{
	if ((in("xX", data->fmt.spec) && \
			data->fmt.hash && \
			data->fmt.buf_tmp[0] != '0') || \
			data->fmt.spec == 'p')
	{
		if (data->fmt.upper_case)
			ft_pstr_buf_n("0X", 2, data);
		else
			ft_pstr_buf_n("0x", 2, data);
	}
}

static void	put_sign(t_data *data)
{
	if (data->fmt.base == BASE_16)
		put_0x(data);
	else if (data->fmt.signed_value)
	{
		if (data->fmt.is_negative)
			ft_pchar_buf_n('-', 1, data);
		else if (!data->fmt.is_negative)
		{
			if (data->fmt.plus)
				ft_pchar_buf_n('+', 1, data);
			else if (!data->fmt.plus && \
					data->fmt.space)
				ft_pchar_buf_n(' ', 1, data);
		}
	}
}

void	ft_print_p(unsigned long int n, t_data *data)
{
	if (n >= 16)
	{
		ft_print_p(n / 16, data);
		ft_print_p(n % 16, data);
	}
	else
	{
		if (n < 10)
			write_buf(data, n + '0');
		else
			write_buf(data, n - 10 + 'a');
	}
}

void	ft_paddr(t_data *data, void *ptr)
{
	unsigned long int	addr;

	addr = (unsigned long int)ptr;
	if (0 == addr)
		ft_pstr(data, "(nil)");
	else
	{
		ft_pstr(data, "0x");
		ft_print_p(addr, data);
	}
}

void	print_int(t_data *data, t_uint int_v)
{
	itoa_buf(data, int_v);
	set_p_zeros(data);
	set_p_spaces(data);
	if (data->fmt.left)
	{
		put_sign(data);
		ft_pchar_buf_n('0', data->fmt.p_zeros, data);
		ft_pstr_buf_n(data->fmt.buf_tmp, data->fmt.nbr_len, data);
		ft_pchar_buf_n(' ', data->fmt.p_zeros, data);
	}
	else
	{
		ft_pchar_buf_n(' ', data->fmt.p_spaces, data);
		put_sign(data);
		ft_pchar_buf_n('0', data->fmt.p_zeros, data);
		ft_pstr_buf_n(data->fmt.buf_tmp, data->fmt.nbr_len, data);
	}
}

// DONE //

/*
 * ft_buffer.c - written
 * ft_parse.c - written
 * ft_printf.c - written
 * ft_printf.h
 * Mkfile
 * ft_c_render.c
 * ft_int_render.c
 *
 *
 *
*/

// TODO //

/*
 * ft_str_render.c
 *
 *
 *
 *
*/
