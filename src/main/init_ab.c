/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:17 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/10 16:18:19 by jroseiro         ###   ########.fr       */
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
		ft_med(stack, name, i, median);
		i++;
	}
}

void	ft_med(t_stack *stack, char *name, int i, int median)
{
	if (name == 'a')
	{
		stack->a->index = i;
		if (i <= median)
			stack->a->above_median = true; // if true, the node is above the median
		else
			stack->a->above_median = false; // if false, the node is below the median
	}
	else if (name == 'b')
	{	
		stack->b->index = i;
		if (i <= median)
			stack->b->above_median = true; // if true, the node is above the median
		else
			stack->b->above_median = false; // if false, the node is below the median
		stack = stack->b->next;
	}
	
}

static void set_target_a(t_stack *stack)
{
	t_node *current_b;
	t_node *target;
	long	best_match_i;

	while (stack->a)
	{
		best_match_i = LONG_MIN; //assign the smallest long as the closest value so far
		current_b = stack->b;
		while (current_b) // search all nodes of b until the end of the stack
		{
			if (current_b->val < stack->a->val
				&& current_b->val > best_match_i) // if the value of b is smaller than the value of a and the value of b is greater than the best match so far
			{
				best_match_i = current_b->val; // assign the value of b to the best match so far
				target = current_b; // assign the node of b to the target
			}
			current_b = current_b->next; // move to the next node of b
		}
		if (best_match_i != LONG_MIN) // if the best match is not the smallest long
			stack->a->target = find_max(stack->b); // assign the target to the node of a
		else
			stack->a->target = target;
		stack->a = stack->a->next; // move to the next node of a to find the target b node
	}
}


static void	cost_a(t_stack *stack)
{
    int len_a;
    int len_b;
    t_node *a = stack->a;
    t_node *b = stack->b;

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

void set_cheapest(t_stack *stack)
{
	long	cheapest_val;
	t_node	*cheapest_node;

	if(!stack)
		return;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->a->p_cost < cheapest_val)
		{
			cheapest_val = stack->a->p_cost;
			cheapest_node = stack->a;
		}
		stack->a = stack->a->next;
	}
	cheapest_node->cheapest = true;
}

void init_nodes_a(t_stack *stack)
{
	current_index(stack, 'a');
	current_index(stack, 'b');
	set_target_a(stack);
	cost_a(stack);
	set_cheapest(stack->a);
}