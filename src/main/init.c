 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:09:37 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/13 10:11:16 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"



void	init_stacks(t_stack *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}





void	init_a(t_node **a, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (sntx_error(av[i])) // check syntax errors
			f_errors(a);
		n = f_atol(av[i]); // bringing the string vals into long
		if (n > INT_MAX || n < INT_MIN) // check for overflow
			f_errors(a);
		if (dup_error(*a, (int)n))
			f_errors(a);
		append_node(a, (int)n); //if no errors, append the node to the linked list by taking a point to A
		i++;
	}
}




