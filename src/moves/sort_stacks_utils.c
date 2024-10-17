/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:04:28 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/17 19:09:29 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	rev_rotate_both(t_node **a,
								t_node **b,
								t_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(a);
	current_index(b);
}

void	rotate_both(t_node **a,
					t_node **b,
					t_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b);
	current_index(a);
	current_index(b);
}

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target, 'b');
	pb(b, a);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(a, b);
}

void	min_on_top(t_node **a)
{
	while ((*a)->val != find_min(*a)->val)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
