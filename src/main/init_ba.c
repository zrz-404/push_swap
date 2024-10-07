/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:22 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/04 15:55:06 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void set_b(t_stack *a, t_stack *b )
{
	t_node	*current_a;
	t_node	*target;
	long	best_match_i;

	while (b)
	{
		best_match_i = LONG_MAX;
		current_a = a;

		while(current_a) //while the pointer is not set to null
		{
			if (current_a->val > b->stack_b->val
				&& current_a->val < best_match_i) // check if 'a' val is bigger then the b node and smaller than the closest buggest number so far
			{
				best_match_i = current_a->val;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_i == LONG_MAX) //if the best match alue has not changed
			b->stack_b->target = target;
		b = b->stack_b->next;
	}
}

void	init_ba(t_stack *a, t_stack *b)
{
	current_index(a->stack_a);
	current_index(b->stack_b);
	set_target_b(a->stack_a, b->stack_b);
}