/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:22 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 21:51:28 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_indices(t_stack **st)
{
	t_stack	*trav;

	trav = *st;
	while (trav)
	{
		trav->index = -1;
		trav = trav->next;
	}
}

void	assign_indices(int size, t_stack **stack)
{
	t_stack	*trav;
	t_stack	*min;
	int		i;

	i = 0;
	initialize_indices(stack);
	while (i < size)
	{
		trav = *stack;
		while (trav->index != -1)
			trav = trav->next;
		min = trav;
		while (trav)
		{
			if (trav->value <= min->value && trav->index == -1)
				min = trav;
			trav = trav->next;
		}
		min->index = i;
		i++;
	}
}
