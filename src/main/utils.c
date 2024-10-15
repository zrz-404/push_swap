/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:33:16 by zrz               #+#    #+#             */
/*   Updated: 2024/10/15 18:27:23 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"


int link_len(t_node *stack)
{
	int	count;

	if (!stack) 
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_node	*find_last(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

bool	stack_sorted(t_node *node)
{
	if (!node)
		return (1);
	while (node->next)
	{
		if (node->val > node->next->val)
			return (false);
		node = node->next; 
	}
	return (true);
}

t_node	*find_min(t_node *node)
{
	long	min;
	t_node	*min_node;

	if (!node)
		return (NULL);
	min = LONG_MAX;
	while (node)
	{
		if (node->val < min)
		{
			min = node->val;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node); 
}

t_node	*find_max(t_node *stack)
{
	long	max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->val > max)
		{
			max = stack->val;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}


/*	BASIC UTILS 
	functions for:
	- Error handling
	- Doing the Operations
	- Measuring stack length
	- Finding the last node
	- Finding the Min and Max nodes
*/
