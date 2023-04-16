/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:31 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 00:39:32 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argtostack(int count, char **args, t_stack **stack_a)
{
	int	i;
	int	val;

	i = 1;
	while (i < count)
	{
		val = (int)ft_atoi(args[count - i]);
		ft_list_push_front(stack_a, val);
		i++;
	}
}
