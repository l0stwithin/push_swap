/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_opns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:12 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 21:51:16 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	rev;

	rev = 0;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
		rotate(stack_a, rev);
	if (*stack_b != NULL && (*stack_b)->next != NULL)
		rotate(stack_b, rev);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	rev;

	rev = 1;
	if (*stack_a != NULL && (*stack_a)->next != NULL)
		rotate(stack_a, rev);
	if (*stack_b != NULL && (*stack_b)->next != NULL)
		rotate(stack_b, rev);
	ft_putendl_fd("rrr", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	st_swap(stack_a);
	st_swap(stack_b);
	ft_putendl_fd("ss", 1);
}
