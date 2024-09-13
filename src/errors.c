/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:09:31 by jroseiro          #+#    #+#             */
/*   Updated: 2024/09/12 16:21:57 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/include.h"

int sntx_error(char *str_n);

int dup_error(t_node *stack_A, int n);

void f_stack(t_node **stack);

void f_errors(t_node **stack_A);