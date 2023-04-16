/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_opns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:40:08 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 00:40:09 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, int reverse)
{
	t_stack	*last;
	t_stack	*trav;
	t_stack	*after_trav;

	trav = *stack;
	while (trav->next != NULL)
	{
		after_trav = trav;
		trav = trav->next;
	}
	last = trav;
	trav = *stack;
	last->next = trav;
	if (reverse == 0)
	{
		*stack = (*stack)->next;
		trav->next = NULL;
	}
	else
	{
		*stack = last;
		after_trav->next = NULL;
	}
}

void	ra(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		rotate(stack_a, 0);
		ft_putendl_fd("ra", 1);
	}
}

void	rb(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		rotate(stack_b, 0);
		ft_putendl_fd("rb", 1);
	}
}

void	rra(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
	{
		rotate(stack_a, 1);
		ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	if (*stack_b != NULL && (*stack_b)->next != NULL)
	{
		rotate(stack_b, 1);
		ft_putendl_fd("rrb", 1);
	}
}
