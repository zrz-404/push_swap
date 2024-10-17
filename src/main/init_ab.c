/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:17 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/17 19:10:24 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	current_index(t_node **stack)
{
	int		i;
	int		median;
	t_node	*temp;

	i = 0;
	if (!stack)
		return ;
	temp = *stack;
	median = link_len(temp) / 2;
	while (temp)
	{
		temp->index = i;
		if (i <= median)
			temp->above_median = true;
		else
			temp->above_median = false;
		temp = temp->next;
		++i;
	}
}

static void	set_target_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node	*target;
	long	best_match_i;

	while (a)
	{
		best_match_i = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->val < a->val
				&& current_b->val > best_match_i)
			{
				best_match_i = current_b->val;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_i == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	cost_a(t_node *a, t_node *b)
{
	int	len_a;
	int	len_b;

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

void	set_cheapest(t_node **stack)
{
	long	cheapest_val;
	t_node	*cheapest_node;
	t_node	*temp;

	if (!stack)
		return ;
	temp = *stack;
	cheapest_val = LONG_MAX;
	while (temp)
	{
		if (temp->p_cost < cheapest_val)
		{
			cheapest_val = temp->p_cost;
			cheapest_node = temp;
		}
		temp = temp->next;
	}
	cheapest_node->cheapest = true;
}

void	init_ab(t_node *a, t_node *b)
{
	current_index(&a);
	current_index(&b);
	set_target_a(a, b);
	cost_a(a, b);
	set_cheapest(&a);
}
