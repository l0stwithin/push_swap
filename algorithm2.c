/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:38:57 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:28:26 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_r(t_stack *elem, t_stack **stack)
{
	int		cost;
	t_stack	*trav;

	cost = 0;
	trav = *stack;
	while (trav != elem && trav)
	{
		cost++;
		trav = trav->next;
	}
	return (cost);
}

int	cost_rr(t_stack *trav)
{
	int	cost;

	cost = 0;
	while (trav)
	{
		cost++;
		trav = trav->next;
	}
	return (cost);
}

int	movetop_cost(t_stack *trav, t_stack **stack)
{
	int	mt_cost;

	mt_cost = ft_minima(cost_r(trav, stack), cost_rr(trav));
	return (mt_cost);
}

void	elem_tosort(int min, int max, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_elem;
	t_stack	*trav;
	int		cost_min;
	int		size;

	size = max - min + 1;
	while (size)
	{
		cost_min = 500;
		trav = *stack_a;
		while (trav)
		{
			if (trav->index >= min && trav->index <= max
				&& movetop_cost(trav, stack_a) < cost_min)
			{
				cost_min = movetop_cost(trav, stack_a);
				min_elem = trav;
			}
			trav = trav->next;
		}
		move_elem(min_elem, stack_a, stack_b);
		apply_push(min_elem, stack_a, stack_b);
		size--;
	}
}

void	presort_nelem(t_stack **stack_a, t_stack **stack_b, int length)
{
	int	num_chunk;
	int	div;
	int	chunk_size;
	int	min_index;

	num_chunk = 1;
	div = 50;
	if (length >= 100)
		num_chunk = length / div;
	chunk_size = length / num_chunk;
	min_index = 0;
	while (min_index + chunk_size < length - 3)
	{
		elem_tosort(min_index, min_index + chunk_size - 1, stack_a, stack_b);
		min_index = min_index + chunk_size;
	}
	elem_tosort(min_index, length - 4, stack_a, stack_b);
	sort_3elem(stack_a, stack_b, 0);
	put_back(stack_a, stack_b, length - 3);
}
