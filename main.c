/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdutta <sdutta@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:37 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/20 02:23:21 by sdutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;

	if (error_check(argc, argv) != 0)
	{
		display_message("Error");
		return (0);
	}
	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	*a = NULL;
	*b = NULL;
	argtostack(argc, argv, a);
	if (ft_isspace(argv[0]))
		argc = word_count(argv[0], ' ');
	assign_indices(argc - 1, a);
	sort_stack(a, b, argc - 1);
	free_stack(a);
	free_stack(b);
	return (0);
}
