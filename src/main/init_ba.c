/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:39:22 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/15 23:17:59 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void	target_b(t_node *a, t_node *b )
{
	t_node	*current_a;
	t_node	*target;
	long	best_match_i;

	while (b)
	{
		best_match_i = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->val > b->val
				&& current_a->val < best_match_i)
			{
				best_match_i = current_a->val;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_i == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_ba(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
