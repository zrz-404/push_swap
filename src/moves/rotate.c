/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:09:47 by zrz               #+#    #+#             */
/*   Updated: 2024/10/14 17:43:30 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void	rotate(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void ra(t_node **a) // rotate a (shift all up by 1, 1st becomes last)
{
	rotate(a);
	ft_printf("ra\n");
}

void rb(t_node **b) // rotate b (shift all up by 1, 1st becomes last)
{
	rotate(b);
	ft_printf("rb\n");
}

void rr(t_node **a, t_node **b) // ra and rb
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}