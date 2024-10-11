/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:22 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/10 12:39:32 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void set_b(t_stack *stack_a, t_stack *stack_b )
{
	t_node	*current_a;
	t_node	*target;
	long	best_match_i;

	while (stack_b)
	{
		best_match_i = LONG_MAX;
		current_a = stack_a;

		while(current_a) //while the pointer is not set to null
		{
			if (current_a->val > stack_b->b->val
				&& current_a->val < best_match_i) // check if 'a' val is bigger then the b node and smaller than the closest buggest number so far
			{
				best_match_i = current_a->val;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_i == LONG_MAX) //if the best match alue has not changed
			stack_b->b->target = target;
		stack_b = stack_b->b->next;
	}
}

void	init_ba(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a->a);
	current_index(stack_b->b);
	set_target_b(stack_a->a, stack_b->b);
}