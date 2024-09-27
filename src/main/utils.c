/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroseiro <jroseiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 19:33:16 by zrz               #+#    #+#             */
/*   Updated: 2024/09/24 14:53:10 by jroseiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"


int link_len(struct s_node *p)
{
	if (p == NULL)
		return (0);
	return (link_len(p->next) + 1);
}



/*	BASIC UTILS 
	functions for:
	- Error handling
	- Doing the Operations
	- Measuring stack length
	- Finding the last node
	- Finding the Min and Max nodes
*/
