/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:08 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/14 16:59:16 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

void	sort_three(t_node **a)
{
	t_node *largest_node; //pointer to largest node

	largest_node = find_max(*a);
	if (largest_node == *a) //  if current node is largest
		ra(a); //if so, rotate top to bot
	else if ((*a)->next == largest_node) //else if second node is largest
		rra(a); // reverse rotate the bot to top
	if ((*a)->val > (*a)->next->val) //check if bottom is largest and top bigger then second
		sa(a);	// swap top and second
}