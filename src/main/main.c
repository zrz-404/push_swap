/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:42:00 by jroseiro          #+#    #+#             */
/*   Updated: 2024/10/10 12:37:22 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int main(int ac, char **av)
{
	t_stack stacks;

	init_stacks(&stacks);
	if (ac < 2 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("Error\n", 3);
		return (1);
	}
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	init_a(&stacks.a, av + 1);
	
	if (!stack_sorted(stacks.a))
	{
		if (stack_len(stacks.a) == 2)
			sa(&stacks.a);
		else if (stack_len(stacks.a) == 3)
			srt_three(&stacks.a);
		else
			srt_stacks(&stacks.a, &stacks.b);
	}
	f_errors(&stacks.a);	
	return (0);
}

				/*				PSEUDO CODE				*/

//Handle input count errors. AC must be 2 or more, and the second input must not be empty
		//If input errors, return error

//Handle both cases of input, whether a variable number of command line arguments, or as a string
		//If the input of numbers comes as a string, call ft_split() to split the substrings

//Initialize stack A by appending each input number as a node to stack A
		//Handle integer overflow, duplicates and syntax errors, ex: input must contain only digits or - or + signs
				// if errors found, free stack A and return error
		//Check each input, if it is a long integer
				// if input is string, convert it to a long integer (long is used to handle larger numbers)
		//(if all else dealt with) Append the nodes to stack A

//Check if stack A is sorted
		//If not sorted, implement our sorting algorithm
				//check if stack A contains only 2 numbers
						//if its just 2 numbers, simply swap them
				//check if stack A contains only 3 numbers
						//if so, implement the simple 'sort three' algorithm
				//check if stack A has more than 3 numbers
						//if so, implement the türk
//Clean up the stack





