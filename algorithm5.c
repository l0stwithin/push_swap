/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:07 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:13:08 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	which_stack(t_stack *elem, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*trav;

	(void)stack_b;
	trav = *stack_a;
	while (trav)
	{
		if (trav->index == elem->index)
			return (0);
		trav = trav->next;
	}
	return (1);
}

int	get_rot_opn(t_stack *elem, t_stack **stack)
{
	int	rotopn;

	if (cost_r(elem, stack) > cost_rr(elem))
		rotopn = 1;
	else
		rotopn = 0;
	return (rotopn);
}

void	apply_move(t_stack **stack_a, t_stack **stack_b,
			t_stack *elem, void (*opn)(t_stack **, t_stack **))
{
	int		i;
	int		n;
	int		aorb;
	t_stack	**stack;

	i = 0;
	aorb = which_stack(elem, stack_a, stack_b);
	stack = stack_a;
	if (aorb)
		stack = stack_b;
	if (get_rot_opn(elem, stack))
		n = cost_rr(elem);
	else
		n = cost_r(elem, stack);
	while (i < n)
	{
		apply_operation(stack_a, stack_b, opn);
		i++;
	}
}

void	apply_push(t_stack *elem, t_stack **stack_a, t_stack **stack_b)
{
	int	aorb;

	aorb = which_stack(elem, stack_a, stack_b);
	if (aorb)
		apply_operation(stack_a, stack_b, &pa);
	else
		apply_operation(stack_a, stack_b, &pb);
}

void	move_elem(t_stack *elem, t_stack **stack_a, t_stack **stack_b)
{
	int		aorb;
	t_stack	**stack;
	void	(*rotopn)(t_stack **, t_stack **);

	aorb = which_stack(elem, stack_a, stack_b);
	if (aorb)
	{
		stack = stack_b;
		if (get_rot_opn(elem, stack))
			rotopn = &rrb;
		else
			rotopn = &rb;
	}
	else
	{
		stack = stack_a;
		if (get_rot_opn(elem, stack))
			rotopn = &rra;
		else
			rotopn = &ra;
	}
	apply_move(stack_a, stack_b, elem, rotopn);
}
