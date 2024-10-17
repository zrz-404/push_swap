/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:31:43 by zrz               #+#    #+#             */
/*   Updated: 2024/10/17 20:53:41 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				val;
	int				index;
	int				p_cost;
	bool			cheapest;
	bool			above_median;

	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

// typedef struct s_stack {
// 	t_node	*a;
// 	t_node	*b;
// }	t_stack;

// Stack init
t_node	*find_min(t_node *node);
t_node	*find_max(t_node *stack);

// Nodes init
void	init_a(t_node **a, char **av);
void	init_ba(t_node *a, t_node *b);
void	init_ab(t_node *a, t_node *b);

// Stack utils
int		link_len(t_node *stack);
bool	stack_sorted(t_node *node);
void	set_cheapest(t_node **stack);
void	current_index(t_node **stack);
t_node	*get_cheapest(t_node *stack);
t_node	*find_last(t_node *node);
char	**split(char *s, char c);

// Moves
void	pa(t_node **a, t_node **b);
void	pb(t_node **b, t_node **a);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

//sort stacks
void	rotate_both(t_node **a,
			t_node **b,
			t_node *cheapest_node);
void	rev_rotate_both(t_node **a,
			t_node **b,
			t_node *cheapest_node);
void	move_a_to_b(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
void	min_on_top(t_node **a);

// Algorithm stuff
void	sort_three(t_node **a);
void	sort_stacks(t_node **a, t_node **b);
void	prep_push(t_node **stack, t_node *top_node, char stack_name);

// Error Handling
int		sntx_error(char *str_n);
int		dup_error(t_node *stack, int n);
void	f_stack(t_node **stack);
void	f_errors(t_node **stack);
void	f_errors_str(t_node **stack, char **av);
void	free_the_world(t_node **stack, char **av_temp);

#endif