/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:42:00 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/17 21:00:34 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void	sorted(t_node *a, t_node *b)
{
	if (link_len(a) == 2)
		sa(&a);
	else if (link_len(a) == 3)
		sort_three(&a);
	else
		sort_stacks(&a, &b);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**av_temp;

	av_temp = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (ac == 2)
	{
		av_temp = split(av[1], ' ');
		init_a(&a, av_temp + 1);
	}
	else
		init_a(&a, av + 1);
	if (!stack_sorted(a))
		sorted(a, b);
	free_the_world(&a, av_temp);
	f_stack(&a);
	return (0);
}

void	f_errors_str(t_node **stack, char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(*av);
	f_stack(stack);
	ft_putstr_fd("Error str\n", 2);
	exit(1);
}
