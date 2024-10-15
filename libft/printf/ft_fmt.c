/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:10:03 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/22 11:33:53 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	in(const char *s, char c)
{
	if (NULL == s)
		return (false);
	while (*s)
	{
		if (*s == c)
			return (true);
		++s;
	}
	return (false);
}

void	set_p_zeros(t_data *data)
{
	if (data->fmt.precision >= 0)
	{
		if (data->fmt.precision >= data->fmt.nbr_len)
		{
			data->fmt.p_zeros = data->fmt.precision - data->fmt.nbr_len;
			return ;
		}
	}
	if (data->fmt.p_zeros)
	{
		if (data->fmt.left)
			return ;
		if (data->fmt.width > data->fmt.nbr_len)
			data->fmt.p_zeros = data->fmt.width - data->fmt.nbr_len;
		if (data->fmt.spec == 'u')
			return ;
		else if ((in("xX", data->fmt.spec) && data->fmt.hash && \
					data->fmt.buf_tmp[0] != '0') || data->fmt.spec == 'p')
			data->fmt.p_zeros -= 2;
		else if (data->fmt.is_negative || (!data->fmt.is_negative && \
					(data->fmt.plus || data->fmt.space)))
			data->fmt.p_zeros--;
	}
	if (data->fmt.p_zeros < 0)
		data->fmt.p_zeros = 0;
}

void	set_p_spaces(t_data *data)
{
	data->fmt.p_spaces = data->fmt.width \
		- data->fmt.p_zeros - data->fmt.nbr_len;
	if (in("uxXp", data->fmt.spec))
	{
		if ((in("xX", data->fmt.spec) && data->fmt.hash && \
				data->fmt.buf_tmp[0] != '0') || data->fmt.spec == 'p')
			data->fmt.p_spaces -= 2;
		return ;
	}
	if (data->fmt.is_negative)
	{
		data->fmt.p_spaces--;
		return ;
	}
	if (!data->fmt.is_negative && data->fmt.plus)
	{
		data->fmt.p_spaces--;
		return ;
	}
	if (!data->fmt.is_negative && data->fmt.space)
	{
		data->fmt.p_spaces--;
		return ;
	}
}
