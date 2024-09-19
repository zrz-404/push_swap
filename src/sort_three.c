/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:08 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/19 21:37:22 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

void	sort_three(t_stack *stack)
{
	t_node *biggest_node; //pointer to biggest node

	biggest_node = find_max(stack->stack_a);
	if (biggest_node == stack->stack_a) //  if current node is biggest
		ra(stack->stack_a); //if so, rotate top to bot
	else if ((stack->stack_a)->next == biggest_node) //else if second node is biggest
		rra(stack->stack_a); // reverse rotate the bot to top
	if ((stack->stack_a)->val > (stack->stack_a)->next->val) //check if bottom is biggest and top bigger then second
		sa(stack->stack_a);	// swap top and second
}