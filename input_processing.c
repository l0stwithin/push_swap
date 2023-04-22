/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdutta <sdutta@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:31 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/23 04:28:38 by sdutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argtostack(int count, char **args, t_stack **stack_a)
{
	int		i;
	int		val;
	char	*str;
	int		mark;

	i = 1;
	mark = 0;
	if (ft_isspace(args[1]) && count == 2)
	{
		str = ft_strdup(args[0]);
		args = ft_split(str, ' ');
		count = word_count(str, ' ');
		mark = 1;
	}
	while (i < count)
	{
		val = (int)ft_atoi(args[count - i]);
		ft_list_push_front(stack_a, val);
		i++;
	}
	if (mark)
	{
		ft_free(args);
		free(str);
	}
}
