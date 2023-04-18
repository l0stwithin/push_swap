/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:15 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/18 18:53:15 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static int	duplicate_val(int count, char **input)
{
	int		i;
	int		j;
	char	*cur_num;

	i = 1;
	while (i < count - 1)
	{
		cur_num = ft_strdup(input[i]);
		j = i + 1;
		while (j < count)
		{
			if (!ft_strcmp(cur_num, input[j]))
				return (TRUE);
			j++;
		}
		free(cur_num);
		i++;
	}
	return (FALSE);
}

static int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (TRUE);
}

static int	out_of_range(char *num)
{
	if (ft_atoi(num) > 2147483647 || ft_atoi(num) < -2147483648)
		return (TRUE);
	return (FALSE);
}

void	display_error(void)
{
	int		fd;
	char	*error_message;

	fd = 1;
	error_message = "Error";
	ft_putendl_fd(error_message, fd);
}

int	error_check(int count, char **strs)
{
	int	i;

	i = 1;
	if (count < 2)
		return (-1);
	if (duplicate_val(count, strs))
	{
		display_error();
		return (TRUE);
	}
	while (i < count)
	{
		if (!ft_isnum(strs[i]) || out_of_range(strs[i]))
		{
			display_error();
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
