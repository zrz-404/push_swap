/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:42:00 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/06 19:34:02 by zrz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

				/*				PSEUDO CODE				*/

//Declare pointers to two linked lists, one for stack A and one for stack B
		//Set both pointers to NULL to avoid undefined behaviour and indicate we're starting with empty stacks

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


/*	BASIC UTILS 
	functions for:
	- Error handling
	- Doing the Operations
	- Measuring stack length
	- Finding the last node
	- Finding the Min and Max nodes
*/