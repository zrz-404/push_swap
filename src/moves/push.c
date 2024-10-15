/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:01 by zrz               #+#    #+#             */
/*   Updated: 2024/10/15 21:50:13 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void push(t_node **dst, t_node **src) //sou rce and destination of the value to be pushed from the two stacks
{
	t_node	*to_push; //storing a pointer to the node to be pushed

	if (!*src)
		return;
	to_push = *src;

	*src = (*src)->next; // move the source stack's head to the next node

	if (*src) // If the new source head exists, update its previous pointer
		(*src)->prev = NULL;
	// Prepare the pushed node for the destination stack
	to_push->prev = NULL;
	if (!*dst)
	{
		*dst = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dst; // assign the node to push to the the top of the stack
		to_push->next->prev = to_push; // 
		*dst = to_push; // finishing appending the node. The pointer to the top node of the stack is now pointing to the pushed node
	}

}

void	pa(t_node **a, t_node **b) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
    ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **b, t_node **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
    ft_putstr_fd("pb\n", 1);
}