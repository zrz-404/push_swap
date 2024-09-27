/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:56:17 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/26 13:32:55 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include.h"

static void swap(t_node **head)
{
	if (!*head || !(*head)->next)
		return;
	*head = (*head)->next; //update head to be the next node
	(*head)->prev->prev = *head; // update the 'prev' pointer of the node before the new head to point to the new head
	(*head)->prev->next = (*head)->next;

	if ((*head)->next) //check if there is a new node after the new head
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
void sa(t_stack *stack) //swap 2 first nodes a
{
	swap(&(stack->stack_a));
	ft_printf("sa\n");
}

void sb(t_stack *stack) //swap 2 first nodes b
{
	swap(&(stack->stack_b));
	ft_printf("sb\n");
}

void ss(t_stack *stack) // sa and sb
{
	swap(&(stack->stack_a));
	swap(&(stack->stack_b));
	ft_printf("ss\n");
}

static void rotate(t_node **stack)
{
	t_node	*last_node; //stores a pointer to the last node of a stack

	if (!*stack || !(*stack)->next)
		return;
	last_node = find_last(* stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

static	void reverse_rotate(t_node **stack)
{
	t_node	*last_node;

	if (!*stack || !(*stack)->next) // check if the stack is empty, or it there's only one node
		return;
	last_node = find_last(* stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL; // detach itself from previous node
	*stack = last_node;
	last_node->next->prev = last_node; //update the current last node of the stack
}

void ra(t_stack *stack) // rotate a (shift all up by 1, 1st becomes last)
{
	rotate(&(stack->stack_a));
	ft_printf("ra\n");
}

void rb(t_stack *stack) // rotate b (shift all up by 1, 1st becomes last)
{
	rotate(&(stack->stack_b));
	ft_printf("rb\n");
}

void rr(t_stack *stack) // ra and rb
{
	rotate(&(stack->stack_a));
	rotate(&(stack->stack_b));
	ft_printf("rr\n");
}

void rra(t_stack *stack) // reverse rotate a (shift all up by 1, last becomes 1st)
{
	reverse_rotate(&(stack->stack_a));
	ft_printf("rra\n");
}

void rrb(t_stack *stack) // reverse rotate b (shift all up by 1, last becomes 1st)
{
	reverse_rotate(&(stack->stack_b));
	ft_printf("rrb\n");
}

void rrr(t_stack *stack) // rra and rrb
{
	reverse_rotate(&(stack->stack_a));
	ft_printf("rra\n");
}


static void push(t_node **dst, t_node **src) //sou rce and destination of the value to be pushed from the two stacks
{
	t_node	*push_node; //storing a pointer to the node to be pushed

	if (!*src)
		return;
	push_node = *src;

	*src = (*src)->next; // move the source stack's head to the next node

	if (*src) // If the new source head exists, update its previous pointer
		(*src)->prev = NULL;
	
	// Prepare the pushed node for the destination stack
	push_node->prev = NULL;

	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}

	else // if the stack we want to push to is not empty
	{
		push_node->next = *dst; // assign the node to push to the the top of the stack
		(*dst)->prev = push_node; // 
		*dst = push_node; // finishing appending the node. The pointer to the top node of the stack is now pointing to the pushed node
	}

}


void pa(t_stack *stack) // push a (top of b to top of a)
{
	push(&(stack->stack_b), &(stack->stack_a));
	ft_printf("pa\n");
}
void pb(t_stack *stack) //push b (top of a to top of b)
{
	push(&(stack->stack_a), &(stack->stack_b));
	ft_printf("pb\n");
}