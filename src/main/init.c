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
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}





void	init_stack_a(t_node **stack_A, char **av)
{
	long	n;
	int		i;

	i = 0;
	while (av[i])
	{
		if (sntx_error(av[i])) // check syntax errors
			f_errors(stack_A);
		n = f_atol(av[i]); // bringing the string vals into long
		if (n > INT_MAX || n < INT_MIN) // check for overflow
			f_errors(stack_A);
		if (dup_error(*stack_A, (int)n))
			f_errors(stack_A);
		append_node(stack_A, (int)n); //if no errors, append the node to the linked list by taking a point to A
		i++;
	}
}




