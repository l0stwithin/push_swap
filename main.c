/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdutta <sdutta@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:37 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/20 06:10:15 by sdutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_message(char *msg)
{
	int		fd;

	fd = 2;
	ft_putendl_fd(msg, fd);
}

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	int			err;

	err = error_check(argc, argv);
	if (err != 0)
	{
		if (err == 1)
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
