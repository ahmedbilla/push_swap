/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:15:28 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 22:33:36 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_biggest(t_list *current, t_list *next_node, t_list *head)
{
	while (current)
	{
		next_node = current->next;
		while (next_node)
		{
			if (current->data > next_node->data)
			{
				swap(&head, 1);
				return ;
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}

void	check_compare(t_list *head)
{
	int		max;
	int		min;
	t_list	*current;
	t_list	*next_node;

	if (!head)
		return ;
	max = head->data;
	min = head->data;
	current = head;
	next_node = NULL;
	while (current)
	{
		if (current->data > max)
			max = current->data;
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	current = head;
	check_biggest(current, next_node, head);
}
