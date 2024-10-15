/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:42:00 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/15 23:20:06 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("Error\n", 3);
		return (1);
	}
	else if (ac == 2)
		av = split(av[1], ' ');
	init_a(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (link_len(a) == 2)
			sa(&a);
		else if (link_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	f_stack(&a);
	return (0);
}
