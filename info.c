/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrz <zrz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 18:42:00 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/06 19:16:01 by zrz              ###   ########.fr       */
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

	after sorting, the program should output the list of operations it has done

	we should also return 'n' size of instructions for sorting 'x' number of values

	if x = 3 then n <= 3
	
	if x = 5 then n <= 12
	
	if x = 100 then n <= 1500

	if x = 500 then n <= 11500

	the lesser the instructions, the more points we get
*/

/*  What is a stack?

    - we can think of it like a stack of objects piled on top of each other
    - IMPORTANT: has a top, and a bottom ( concept comming from linked lists - refresh linked lists)
        - it is an organised data structure containing 'nodes'
        - nodes are data elements, each like a box, that stores a value inside, like numbers, values, etc
        - the most upper node (or first of the list) is called head, and the last one tail
        - each node is connected in sequence
        - a singly linked list is unidirectional
        - a doubly linked list is bi-directional
        - Tail's *next->NULL it points to null bcs it is over

        - for this project, nodes must contain:
            - The data: 
                a value     (type int)
                its index   (type int)

            - Reference Pointers:
                *next node
                *prev node
*/

//      sorting algorithm       //
/*
    The turk algorithm:

        - Until there are 3 nodes left in stack A:
            - Push all nodes from stack A to stack B
            - During each push, B is sorted in descending order

        Target nodes are needed. Each node of stack A should target a node from B
            - A target node is the closest smaller number to the A node
                - IMPORTANT: if no closest smaller number is found, the target node is the MAX value
            - this is what will allow the program to identify the correct move
        
        After each A node has a target, we should do cost analysis:
            - find the 'cheapest' node to push
            - the formula:

                x operations to bring A on top
            +   x operations to bring A->target node on top
            -------------------------------------------------
            = push cost


*/

/*  



*/