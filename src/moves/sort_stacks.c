/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:04:28 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/26 14:44:58 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

t_node *get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest);
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	sort_stacks(t_stack *stack)
{
	int len_a;
	
	len_a = link_len;
	if (len_a-- > 3 && !stack_sorted(*stack))
		pb(stack->stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack))
		pb(stack->stack_b);
	while (len_a -- > 3 && !stack_sorted(*stack))
	{
		init_node_a(stack->stack_a, stack->stack_b);
		move_a_to_b(stack->stack_a, stack->stack_b);
	}
	sorth_three(stack->stack_a);
	while (stack->stack_b) // until the end of stack b is reached
	{
		init_node_b(stack->stack_a, stack->stack_b);
		a_to_b(stack->stack_a, stack->stack_b); // move all 'b' nodes back to a sorted a stack
	}
	current_index(stack->stack_a); // refresh the current position of stack a
	min_on_top(stack->stack_a);
}