/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:08 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/10 12:36:37 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	sort_three(t_stack *stack)
{
	t_node *biggest_node; //pointer to biggest node

	biggest_node = find_max(stack->a);
	if (biggest_node == stack->a) //  if current node is biggest
		ra(stack->a); //if so, rotate top to bot
	else if ((stack->a)->next == biggest_node) //else if second node is biggest
		rra(stack->a); // reverse rotate the bot to top
	if ((stack->a)->val > (stack->a)->next->val) //check if bottom is biggest and top bigger then second
		sa(stack->a);	// swap top and second
}