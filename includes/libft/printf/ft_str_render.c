/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:51:03 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/19 09:14:53 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_s_pad_spcs(t_data *data, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (data->fmt.width > 0)
	{
		if (data->fmt.precision >= 0)
		{
			if (data->fmt.precision > len)
			{
				data->fmt.p_spaces = data->fmt.width - len;
			}
			else if (data->fmt.precision < len)
			{
				data->fmt.p_spaces = data->fmt.width - \
					data->fmt.precision;
			}
		}
		else
		{
			data->fmt.p_spaces = data->fmt.width - len;
		}
	}
}

void	ft_pstr(t_data *data, char *s)
{
	if (NULL == s)
		s = "(null)";
	set_s_pad_spcs(data, s);
	if (data->fmt.left)
	{
		if (data->fmt.precision >= 0)
			ft_pstr_buf_n(s, data->fmt.precision, data);
		else
			ft_pstr_buf_n(s, ft_strlen(s), data);
		ft_pchar_buf_n(' ', data->fmt.p_spaces, data);
	}
	else
	{
		ft_pchar_buf_n(' ', data->fmt.p_spaces, data);
		if (data->fmt.precision >= 0)
			ft_pstr_buf_n(s, data->fmt.precision, data);
		else
			ft_pstr_buf_n(s, ft_strlen(s), data);
	}
}
