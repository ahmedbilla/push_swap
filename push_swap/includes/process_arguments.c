/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:44:03 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/17 13:18:25 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_numeric_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		if (!is_numeric(split_args[i]))
		{
			write(2, "Error\n", 6);
			i = 0;
			while (split_args[i])
				free(split_args[i++]);
			free(split_args);
			return (1);
		}
		i++;
	}
	return (0);
}

int	process_arguments(int ac, char *av[])
{
	int		j;
	int		i;
	char	**split_args;

	j = 1;
	while (j < ac)
	{
		split_args = ft_split(av[j], ' ');
		if (!split_args || !split_args[0])
		{
			write(2, "Error\n", 6);
			free(split_args);
			return (1);
		}
		if (validate_numeric_args(split_args))
			return (1);
		i = 0;
		while (split_args[i])
			free(split_args[i++]);
		free(split_args);
		j++;
	}
	return (0);
}
