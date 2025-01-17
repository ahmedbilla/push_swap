/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:18:41 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/15 20:58:36 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	chose_algo(t_list **head, t_list **b)
{
	int	size;

	size = list_size(*head);
	if (size == 2)
		check_compare(*head);
	else if (size == 3)
		check_compare_three(head);
	else if (size == 4)
		check_compare_four(head, b);
	else if (size == 5)
		check_compare_five(head, b);
	else if (size > 5)
	{
		index_stack_elements(head);
		sort_utils(head, b);
		check_more_five(head, b);
	}
}

int	process_split_args(char **split_args, t_list **head)
{
	int		i;
	long	num;

	i = 0;
	while (split_args[i])
	{
		num = ft_atoi(split_args[i]);
		append_node(head, num);
		if (has_duplicate(*head))
		{
			write(2, "Error\n", 6);
			free_list(*head);
			return (1);
		}
		i++;
	}
	i = 0;
	while (split_args[i])
		free(split_args[i++]);
	free(split_args);
	return (0);
}

int	handle_arguments(int ac, char *av[], t_list **head)
{
	int		j;
	char	**split_args;

	j = 1;
	if (process_arguments(ac, av))
		return (-1);
	while (j < ac)
	{
		split_args = ft_split(av[j], ' ');
		if (split_args)
		{
			if (process_split_args(split_args, head))
				return (1);
		}
		j++;
	}
	return (0);
}

void	finalize_execution(t_list **head, t_list **b)
{
	chose_algo(head, b);
	free_list(*head);
}

int	main(int ac, char *av[])
{
	t_list	*head;
	t_list	*b;

	head = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (handle_arguments(ac, av, &head))
			return (1);
		finalize_execution(&head, &b);
	}
	else
		return (-1);
	return (0);
}
