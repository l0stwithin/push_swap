/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdutta <sdutta@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:15 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/20 02:06:31 by sdutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
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

void	display_message(char *msg)
{
	int		fd;

	fd = 2;
	ft_putendl_fd(msg, fd);
}

int	error_check(int count, char **strs)
{
	int		i;
	int		mac_case;
	char	*str;

	i = count;
	mac_case = 0;
	if (count < 2)
		return (-1);
	if (ft_isspace(strs[1]) && count == 2)
	{
		str = ft_strcat_spc(strs[0], strs[1]);
		strs = ft_split(str, ' ');
		i = word_count(str, ' ');
	}
	if (duplicate_val(count, strs))
		mac_case = 1;
	while (i > 1)
	{
		if (!ft_isnum(strs[i - 1]) || out_of_range(strs[i - 1]))
			mac_case = 1;
		i--;
	}
	if (count == 2)
		ft_free(strs);
	return (mac_case);
}
