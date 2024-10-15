/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:20:30 by zrz               #+#    #+#             */
/*   Updated: 2024/10/15 21:50:31 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static	void reverse_rotate(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next) // check if the stack is empty, or it there's only one node
		return;
	last_node = find_last(* stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL; // detach itself from previous node
	*stack = last_node;
	last_node->next->prev = last_node; //update the current last node of the stack
}


void rra(t_node **a) // reverse rotate a (shift all up by 1, last becomes 1st)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void rrb(t_node **b) // reverse rotate b (shift all up by 1, last becomes 1st)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void rrr(t_node **a, t_node **b) // rra and rrb
{
	reverse_rotate(a);
    reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
