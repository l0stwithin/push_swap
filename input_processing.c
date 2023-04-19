/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdutta <sdutta@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:31 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/20 02:12:19 by sdutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argtostack(int count, char **args, t_stack **stack_a)
{
	int		i;
	int		val;
	char	*str;

	i = 1;
	if (ft_isspace(args[1]) && count == 2)
	{
		str = ft_strdup(args[0]);
		args = ft_split(str, ' ');
		count = word_count(str, ' ');
		free(str);
	}
	while (i < count)
	{
		val = (int)ft_atoi(args[count - i]);
		printf("%d\n", val);
		ft_list_push_front(stack_a, val);
		i++;
	}
	if (count == 2)
		ft_free(args);
}
