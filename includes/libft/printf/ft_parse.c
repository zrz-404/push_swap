/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:59:50 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/22 11:55:31 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// by using booleans wrong inputs are dealt with
static int	fatoi(t_data *data)
{
	int		value;

	value = 0;
	while (in(NUMBERS, *data->s))
		value = (value * 10) + (*data->s++ - '0');
	return (value);
}

static void	parse_flags(t_data *data)
{
	char	flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		if ('0' == flag)
			data->fmt.zero = true;
		else if ('+' == flag)
			data->fmt.plus = true;
		else if (' ' == flag)
			data->fmt.space = true;
		else if ('#' == flag)
			data->fmt.hash = true;
		else if ('-' == flag)
			data->fmt.left = true;
		++data->s;
	}
}

static void	get_val(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		++data->s;
		return ;
	}
	*value = fatoi(data);
}

static void	set_xxp(t_format *fmt, char spec)
{
	if ('x' == spec || 'X' == spec || 'p' == spec)
	{
		fmt->base = BASE_16;
		if ('X' == spec)
			fmt->upper_case = true;
		if ('p' == spec)
			fmt->hash = true;
	}
}

int	parse_format(t_data *data)
{
	ft_memset(&data->fmt, 0, sizeof(t_format));
	data->fmt.precision = -1;
	parse_flags(data);
	get_val(data, &data->fmt.width);
	if (*data->s == '.' && *(++data->s))
		get_val(data, &data->fmt.precision);
	if (!in(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		data->fmt.spec = *data->s;
		if (in("diu", data->fmt.spec))
			data->fmt.base = BASE_10;
		else
		{
			set_xxp(&data->fmt, data->fmt.spec);
		}
	}
	return (OK);
}
