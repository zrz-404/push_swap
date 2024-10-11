/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:04:28 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/10 12:37:33 by jroseiro         ###   ########.fr       */
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
	
	len_a = link_len(stack->a);
	if (len_a-- > 3 && !stack_sorted(*stack))
		pb(stack->a);
	if (len_a-- > 3 && !stack_sorted(*stack))
		pb(stack->b);
	while (len_a -- > 3 && !stack_sorted(*stack))
	{
		init_node_a(stack->a, stack->b);
		move_a_to_b(stack->a, stack->b);
	}
	sorth_three(stack->a);
	while (stack->b) // until the end of stack b is reached
	{
		init_node_b(stack->a, stack->b);
		a_to_b(stack->a, stack->b); // move all 'b' nodes back to a sorted a stack
	}
	current_index(stack->a); // refresh the current position of stack a
	min_on_top(stack->a);
}