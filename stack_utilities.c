/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:40:11 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:07:23 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_create_elem(int data)
{
	t_stack	*new_elem;

	new_elem = malloc(sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->value = data;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_list_push_front(t_stack **begin_list, int data)
{
	t_stack	*front_input;

	front_input = ft_create_elem(data);
	front_input->next = *begin_list;
	*begin_list = front_input;
}

void	apply_operation(t_stack **stack_a, t_stack **stack_b,
						void (*st_opn)(t_stack**, t_stack**))
{
	st_opn(stack_a, stack_b);
}

t_stack	*get_min(t_stack **stack)
{
	t_stack	*trav;
	t_stack	*min;

	trav = *stack;
	min = trav;
	while (trav)
	{
		if (trav->index < min->index)
			min = trav;
		trav = trav->next;
	}
	return (min);
}

int	is_min(t_stack **elem, t_stack **stack)
{
	t_stack	*min;

	min = get_min(stack);
	if ((*elem)->index == min->index)
		return (TRUE);
	else
		return (FALSE);
}
