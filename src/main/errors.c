/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:09:31 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/15 22:49:31 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/include.h"

int sntx_error(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) //Check if the first character of the input string does not contain a sign or a digit
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9')) //Check if the first character of the input string contains a sign, but the second character does not contain a digit
		return (1);
	while (*++str_n) //If the error conditions above are passed, pre-increment to point to the next character in the string, and loop until the end of the string is reached
	{
		if (!(*str_n >= '0' && *str_n <= '9')) //Check if the next character in the string is not a digit
			return (1);
	}
	return (0);
}

int dup_error(t_node *stack, int n)
{
	if (!stack) //Check for an empty stack
		return (0);
	while (stack) //Loop until the end of the stack
	{
		if (stack->val == n) //Check if the value of the current node is equal to the input number
			return (1);
		stack = stack->next; //Move to the next node to check for duplicates
	}
	return (0);
}

void f_stack(t_node **stack) // Free the stack
{
	t_node	*tmp; // To store the next node in the stack before the current node is freed
	t_node	*current;

	if (!stack) // Check for an empty stack
		return;
	current = *stack; // Assign the first node of the stack to `current`
	while (current) // As long as a node exists in the stack
	{
		tmp = current->next; // Assign to `tmp` the pointer to the next node
		current->val = 0; // Assigning the node to `0` before freeing is not strictly necessary
		free(current); // Free the current node, deallocating the memory occupied by that node
		current = tmp; // Assign `tmp` as the current first node
	}
	*stack = NULL; // Assign the stack to `NULL` after freeing all nodes
}

void f_errors(t_node **stack)
{
	f_stack(stack);
	ft_putstr_fd("Error\n", 2); // Print error message
	exit(1);
}