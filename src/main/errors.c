/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:09:31 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/17 21:04:29 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	sntx_error(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

int	dup_error(t_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->val == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_the_world(t_node **stack, char **av_temp)
{
	int	i;

	(void)stack;
	i = 0;
	if (av_temp)
	{
		while (av_temp[i])
		{
			free(av_temp[i]);
			i++;
		}
		free(av_temp);
	}
}

void	f_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(current);
	*stack = NULL;
}

void	f_errors(t_node **stack)
{
	f_stack(stack);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
