/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:00 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:31:21 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min_elem(t_stack *elem, t_stack **stack)
{
	t_stack	*trav;

	trav = *stack;
	while (trav)
	{
		if (elem->index > trav->index)
			return (FALSE);
		trav = trav->next;
	}
	return (TRUE);
}

int	get_cost(t_stack **stack_a, t_stack **stack_b,
		t_stack *elem, t_stack *targ)
{
	int	costr;
	int	costrr;
	int	cost;
	int	cost_ind;

	costr = ft_maxima(cost_r(targ, stack_a), cost_r(elem, stack_b));
	costrr = ft_maxima(cost_rr(targ), cost_rr(elem));
	cost = ft_minima(costr, costrr);
	cost_ind = movetop_cost(elem, stack_b) + movetop_cost(targ, stack_a);
	cost = ft_minima(cost, cost_ind);
	return (cost);
}

t_stack	*get_targ_elem(t_stack *elem, t_stack **stack)
{
	t_stack	*trav;
	t_stack	*base;
	t_stack	*targ;
	int		ismin;

	ismin = is_min_elem(elem, stack);
	trav = *stack;
	if (ismin)
	{
		targ = get_min(stack);
		return (targ);
	}
	while (trav)
	{
		if (trav->next)
			base = trav->next;
		else
			base = *stack;
		if (elem->index > trav->index && elem->index < base->index)
			targ = base;
		trav = trav->next;
	}
	return (targ);
}

t_stack	*lcost_elem(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*trav;
	t_stack	*targ;
	t_stack	*elem;
	int		cost;
	int		cost_min;

	cost_min = 500;
	trav = *stack_b;
	while (trav)
	{
		targ = get_targ_elem(trav, stack_a);
		cost = get_cost(stack_a, stack_b, trav, targ);
		if (cost < cost_min)
		{
			cost_min = cost;
			elem = trav;
		}
		trav = trav->next;
	}
	return (elem);
}

void	put_back(t_stack **stack_a, t_stack **stack_b, int size_b)
{
	t_stack	*elem;
	int		i;

	i = 0;
	while (i < size_b)
	{
		elem = lcost_elem(stack_a, stack_b);
		send_elem_back(elem, stack_a, stack_b);
		i++;
	}
}
