/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:09:31 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/10 12:37:12 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/include.h"

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

int dup_error(t_stack *stack, int n)
{
	t_node *a;

	a = stack->a; //Assign the address of the stack `a` to the pointer `a`
	if (!a) //Check for an empty stack
		return (0);
	while (a) //Loop until the end of stack `a` is reached
	{
		if (a->val == n) //Check if the current node's value is equal to `n`. Refer to `init_a()`
			return (1);
		a = a->next; //Move to the next node to check for duplicates
	}
	return (0);
}

void f_stack(t_stack *stack, char stack_name)
{
	t_node *tmp; // To store the next node in the stack before the current node is freed
	t_node *current;

	if (!stack) // Check for an empty stack
		return;
	if (stack_name == 'a')
		current = stack->a;
	else if (stack_name == 'b')
		current = stack->b;
	else
		return; // Invalid stack name
	while (current) // As long as a node exists in the stack
	{
		tmp = current->next; // Assign to `tmp` the pointer to the next node
		current->val = 0; // Assigning the node to `0` before freeing is not strictly necessary
		free(current); // Free the current node, deallocating the memory occupied by that node
		current = tmp; // Assign `tmp` as the current first node
	}
	if (stack_name == 'a')
		stack->a = NULL;
	else if (stack_name == 'b')
		stack->b = NULL;
}

void f_errors(t_stack *a)
{
	f_stack(a, 'a'); // Free stack A
	ft_putstr_fd("Error\n", 2); // Print error message
	exit(1); // Exit the program
}