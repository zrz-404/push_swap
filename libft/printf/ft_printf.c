/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 14:50:16 by jroseiro          #+#    #+#             */
/*   Updated: 2024/07/19 09:26:47 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	render_char_format(t_data *data)
{
	char	specifier;

	specifier = data->fmt.spec;
	if ('%' == specifier)
		ft_pchar(data, '%');
	else if ('c' == specifier)
		ft_pchar(data, va_arg(data->ap, int));
	else if ('s' == specifier)
		ft_pstr(data, va_arg(data->ap, char *));
}

static void	render_int_format(t_data *data)
{
	char	specifier;
	t_uint	int_v;

	specifier = data->fmt.spec;
	int_v.int64 = 0;
	if (in("dipxXu", specifier))
	{
		if (in("di", specifier))
		{
			int_v.int64 = (long)va_arg(data->ap, int);
			data->fmt.signed_value = true;
			if (int_v.int64 < 0)
				data->fmt.is_negative = true;
		}
		else if ('p' == specifier)
			int_v.uint64 = (unsigned long)va_arg(data->ap, void *);
		else if (in("xXu", specifier))
			int_v.uint64 = (unsigned long)va_arg(data->ap, unsigned int);
		print_int(data, int_v);
	}
}

void	render_format(t_data *data)
{
	char	specifier;

	specifier = data->fmt.spec;
	if (in("dixXu", specifier))
		render_int_format(data);
	else if ('p' == specifier)
		ft_paddr(data, va_arg(data->ap, void *));
	else
		render_char_format(data);
}

static int	init_data(t_data *data, const char *format)
{
	data->c_written = 0;
	data->s = format;
	data->buf = malloc(BUF_SIZE * sizeof(char));
	if (NULL == data->buf)
		return (MALLOC_ERROR);
	data->b_index = 0;
	ft_memset(data->buf, 0, BUF_SIZE * sizeof(char));
	return (OK);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (MALLOC_ERROR);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (parse_format(&data))
			{
				free(data.buf);
				return (PARSE_ERROR);
			}
			render_format(&data);
		}
		else
			write_buf(&data, *data.s);
		++data.s;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buf);
	return (data.c_written);
}

/*

int ft_printf(const char *format, ...)
{
		va_list		args;
	int			i;
	char		*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	i = 0;
	va_start(args, format);
	i = ft_parse(str, args);
	va_end(args);
	free(str);
	return (i);
}

*/
