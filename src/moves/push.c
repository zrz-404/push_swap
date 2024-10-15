/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:57:01 by zrz               #+#    #+#             */
/*   Updated: 2024/10/15 23:06:46 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void	push(t_node **dst, t_node **src)
{
	t_node	*to_push;

	if (!*src)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (!*dst)
	{
		*dst = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dst;
		to_push->next->prev = to_push;
		*dst = to_push;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **b, t_node **a)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
