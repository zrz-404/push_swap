/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:17 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/07 15:06:56 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	current_index(t_stack *stack, char *name)
{
	int	i;
	int	median;

	i = 0;
	if (!stack) //check for an empty stack
		return;
	median = link_len(stack) / 2;
	while (stack)
	{
		if (name == 'a')
			stack->stack_a->index = i;
		if (name == 'b')
			stack->stack_b->index = i;
	}
}