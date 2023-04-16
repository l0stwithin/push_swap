/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:04 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:40:56 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_operation(t_stack *elem, t_stack **stack_a, t_stack **stack_b)
{
	int		aorb;
	t_stack	*targ;

	targ = get_targ_elem(elem, stack_a);
	if (targ == *stack_a && elem != *stack_b)
		targ = elem;
	aorb = which_stack(elem, stack_a, stack_b);
	move_elem(targ, stack_a, stack_b);
	if (aorb)
		apply_push(elem, stack_a, stack_b);
}

void	do_individual_operation(t_stack *elem, t_stack **stack_a,
			t_stack *targ, t_stack **stack_b)
{
	void	(*getopn_b)(t_stack **, t_stack **);
	void	(*getopn_a)(t_stack **, t_stack **);
	int		nb;
	int		na;
	int		i;

	i = -1;
	if (cost_r(elem, stack_b) > cost_rr(elem))
		getopn_b = &rrb;
	else
		getopn_b = &rb;
	nb = ft_minima(cost_r(elem, stack_b), cost_rr(elem));
	if (cost_r(targ, stack_a) > cost_rr(targ))
		getopn_a = &rra;
	else
		getopn_a = &ra;
	na = ft_minima(cost_r(targ, stack_a), cost_rr(targ));
	while (++i < na)
		apply_operation(stack_a, stack_b, getopn_a);
	i = -1;
	while (++i < nb)
		apply_operation(stack_a, stack_b, getopn_b);
	final_operation(elem, stack_a, stack_b);
}

void	do_simultaneous_operation(t_stack *elem, t_stack **stack_a,
		t_stack **stack_b, void (*opn)(t_stack **, t_stack **))
{
	int		n;
	int		i;
	t_stack	*targ;

	i = 0;
	n = 0;
	targ = get_targ_elem(elem, stack_a);
	if (opn == &rr)
		n = ft_minima(cost_r(targ, stack_a), cost_r(elem, stack_b));
	if (opn == &rrr)
		n = ft_minima(cost_rr(targ), cost_rr(elem));
	while (i < n)
	{
		apply_operation(stack_a, stack_b, opn);
		i++;
	}
	final_operation(elem, stack_a, stack_b);
}

void	send_elem_back(t_stack *elem, t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	t_stack	*targ;
	void	(*getopn)(t_stack **, t_stack **);

	targ = get_targ_elem(elem, stack_a);
	cost = ft_maxima(cost_r(targ, stack_a), cost_r(elem, stack_b));
	if (cost_rr(elem) < cost || cost_rr(targ) < cost)
	{
		getopn = &rrr;
		if (cost_rr(elem) < cost_rr(targ))
			cost = cost_rr(targ);
		else
			cost = cost_rr(elem);
	}
	else
		getopn = &rr;
	if (cost > movetop_cost(elem, stack_b) + movetop_cost(targ, stack_a))
		do_individual_operation(elem, stack_a, targ, stack_b);
	else
		do_simultaneous_operation(elem, stack_a, stack_b, getopn);
}
