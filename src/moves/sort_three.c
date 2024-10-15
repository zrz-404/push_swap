/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:08 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/15 18:42:18 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	sort_three(t_node **a)
{
	t_node *largest_node;

	largest_node = find_max(*a);
	if (largest_node == *a)
		ra(a);
	else if ((*a)->next == largest_node)
		rra(a);
	if ((*a)->val > (*a)->next->val)
		sa(a);
}