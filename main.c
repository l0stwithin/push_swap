/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:37 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:50:14 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			error;
	t_stack		**a;
	t_stack		**b;

	error = error_check(argc, argv);
	if (error != 0)
		return (0);
	a = malloc(sizeof(t_stack *));
	if (!a)
		return (0);
	*a = NULL;
	argtostack(argc, argv, a);
	assign_indices(argc - 1, a);
	b = malloc(sizeof(t_stack *));
	if (!b)
		return (0);
	*b = NULL;
	sort_stack(a, b, argc - 1);
	write(1, "stack_a\n", 8);
	 while (*a)            //test loop                        
    {
        printf("%d\t", (*a)->value);
        printf("%d\n", (*a)->index);
        *a = (*a)->next;
    }
	free_stack(a);
	free_stack(b);
	return (0);
}
