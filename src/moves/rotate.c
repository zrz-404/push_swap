/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:09:47 by zrz               #+#    #+#             */
/*   Updated: 2024/10/15 23:08:51 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void	rotate(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
