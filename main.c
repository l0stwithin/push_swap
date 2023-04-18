/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:37 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/18 23:44:01 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	char		*str;

	if (ft_isspace(argv[1]))
	{
		str = ft_strcat_spc(argv[0], argv[1]);
		argv = ft_split(str, ' ');
		argc = word_count(str, ' ');
	}
	if (error_check(argc, argv) != 0)
		return (0);
	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	if (!a || !b)
		return (0);
	*a = NULL;
	*b = NULL;
	argtostack(argc, argv, a);
	assign_indices(argc - 1, a);
	sort_stack(a, b, argc - 1);
	free_stack(a);
	free_stack(b);
	return (0);
}
