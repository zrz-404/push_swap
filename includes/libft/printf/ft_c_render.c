/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:51:03 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/19 08:59:14 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pchar(t_data *data, int c)
{
	int	width;

	width = data->fmt.width;
	if (width > 1)
	{
		if (data->fmt.left)
		{
			ft_pchar_buf_n((char)c, 1, data);
			ft_pchar_buf_n(' ', width -1, data);
		}
		else
		{
			ft_pchar_buf_n(' ', width - 1, data);
			ft_pchar_buf_n((char)c, 1, data);
		}
	}
	else
		ft_pchar_buf_n((char)c, 1, data);
}
