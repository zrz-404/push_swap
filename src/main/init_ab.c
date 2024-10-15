/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:17 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/15 21:22:56 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	current_index(t_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack) //check for an empty stack
		return;
	median = link_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}


static void set_target_a(t_node *a, t_node *b)
{
	t_node *current_b;
	t_node *target;
	long	best_match_i;

	while (a)
	{
		best_match_i = LONG_MIN; //assign the smallest long as the closest value so far
		current_b = b;
		while (current_b) // search all nodes of b until the end of the stack
		{
			if (current_b->val < a->val
				&& current_b->val > best_match_i) // if the value of b is smaller than the value of a and the value of b is greater than the best match so far
			{
				best_match_i = current_b->val; // assign the value of b to the best match so far
				target = current_b; // assign the node of b to the target
			}
			current_b = current_b->next; // move to the next node of b
		}
		if (best_match_i == LONG_MIN) // if the best match is not the smallest long
			a->target = find_max(b); // assign the target to the node of a
		else
			a->target = target;
		a = a->next; // move to the next node of a to find the target b node
	}
}


static void	cost_a(t_node *a, t_node *b)
{
    int len_a;
    int len_b;

    len_a = link_len(a);
    len_b = link_len(b);
    while (a)
    {
        a->p_cost = a->index;
        if (!(a->above_median))
            a->p_cost = len_a - (a->index);
        if (a->target->above_median)
            a->p_cost += a->target->index;
        else
            a->p_cost += len_b - (a->target->index);
        a = a->next;
    }
}

void set_cheapest(t_node *stack)
{
	long	cheapest_val;
	t_node	*cheapest_node;

	if(!stack)
		return;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->p_cost < cheapest_val)
		{
			cheapest_val = stack->p_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void init_ab(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}