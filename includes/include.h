/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:31:43 by zrz               #+#    #+#             */
/*   Updated: 2024/10/10 12:36:04 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include "./libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node {
	int			val;
	int			index;
	int			p_cost;
	bool		cheapest;
	bool		above_median;

	struct s_node		*next;
	struct s_node		*prev;
	struct s_node 		*target;
} t_node;

typedef struct s_stack {
	t_node	*a;
	t_node	*b;
}	t_stack;


// Stack init

// Nodes init
t_node	*get_cheapest(t_node *stack);

// Stack utils
int		link_len(struct s_node *p);
void 	init_stacks(t_stack *stacks);

// Moves
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack);
void	pa(t_stack *stack);
void	pb(t_stack *stack);

// Algorithm stuff
void	sort_stacks(t_stack *stack);


// Error Handling

#endif