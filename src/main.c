/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:42:00 by jroseiro          #+#    #+#             */
/*   Updated: 2024/08/30 19:09:26 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




// 2 stacks, 'a' and 'b'
// at start:
	// a contains a random amount of negative and/or positive numbers which cannot be duplicated
	// the stack b is empty
// goal is to sort in ascending order numbers into stack *a*

/*to do so, we can:

	sa -> (swap a) : Swap the first 2 elements at the top of stack ' a '
					Do nothing if there is only one or no elements

	sb -> (swap b) ; Swap the first 2 elements at the top of stack ' b '
					Do nothing if there is only one or no elements

	ss -> ' sa ' and ' sb ' at the same time

	pa -> push a






*/