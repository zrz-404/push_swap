/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:09:37 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/12 11:51:03 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	init_A(t_node **stack_A, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (sntx_error(av[i]))
			f_errors(stack_A);
		n = f_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			f_errors(stack_A);
		if (dup_error(*stack_A, (int)n))
			f_errors(stack_A);
		append_node(stack_A, (int)n);
		i++;
	}
}