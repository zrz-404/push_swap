/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:56:17 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/15 14:13:28 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return;
	*head = (*head)->next; //update head to be the next node
	(*head)->prev->prev = *head; // update the 'prev' pointer of the node before the new head to point to the new head
	(*head)->prev->next = (*head)->next;

	if ((*head)->next) //check if there is a new node after the new head
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
void	sa(t_node **a) //swap 2 first nodes a
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_node **b) //swap 2 first nodes b
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b) // sa and sb
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
