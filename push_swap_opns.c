/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:41 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 00:39:42 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b != NULL)
	{
		temp = *stack_a;
		*stack_a = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_a)->next = temp;
		ft_putendl_fd("pa", 1);
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a != NULL)
	{
		temp = *stack_b;
		*stack_b = *stack_a;
		*stack_a = (*stack_a)->next;
		(*stack_b)->next = temp;
		ft_putendl_fd("pb", 1);
	}
}

void	st_swap(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp2 = (*stack)->next;
		(*stack)->next = temp;
		temp->next = temp2;
	}
}

void	sa(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_b;
	st_swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_a, t_stack **stack_b)
{
	(void)stack_a;
	st_swap(stack_b);
	ft_putendl_fd("sb", 1);
}
