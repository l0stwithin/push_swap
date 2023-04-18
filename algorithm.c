/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:38:53 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/18 18:51:47 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack **top, void (*rot)(t_stack**, t_stack**),
		t_stack **other, void (*revrot)(t_stack**, t_stack**))
{
	t_stack	*first;
	t_stack	*mid;
	t_stack	*last;

	first = *top;
	mid = first->next;
	last = mid->next;
	if (last->index < mid->index && last->index < first->index)
		apply_operation(top, other, revrot);
	else if (!(last->index > mid->index && last->index > first->index))
		apply_operation(top, other, rot);
}

int	rot_dir3(t_stack **stack)
{
	t_stack	*trav;
	t_stack	*fol;
	int		dir;

	dir = 1;
	trav = *stack;
	while (trav->next != NULL)
	{
		fol = trav->next;
		if (trav->index > fol->index)
			dir = (-1) * dir;
		trav = trav->next;
	}
	if (trav->index > (*stack)->index)
		dir = (-1) * dir;
	return (dir);
}

void	sort_3elem(t_stack **stack_a, t_stack **stack_b, int aorb)
{
	int		rd;
	void	(*swap_top)(t_stack **, t_stack **);
	void	(*rot)(t_stack **, t_stack **);
	void	(*revrot)(t_stack **, t_stack **);

	if (!aorb)
	{
		swap_top = &sa;
		rot = &ra;
		revrot = &rra;
		rd = rot_dir3(stack_a);
	}
	else
	{
		swap_top = &sb;
		rot = &rb;
		revrot = &rrb;
		rd = rot_dir3(stack_b);
	}
	if (rd == 1)
		apply_operation(stack_a, stack_b, swap_top);
	sort3(stack_a, rot, stack_b, revrot);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*elem;

	elem = NULL;
	if (size == 1 || is_sorted(stack_a))
		return ;
	else if (size == 2 && (*stack_a)->index == 1)
		apply_operation(stack_a, stack_b, &sa);
	else if (size == 3)
		sort_3elem(stack_a, stack_b, 0);
	else if (size > 3)
		presort_nelem(stack_a, stack_b, size);
	if (!is_sorted(stack_a))
	{
		elem = get_min(stack_a);
		move_elem(elem, stack_a, stack_b);
	}
}
