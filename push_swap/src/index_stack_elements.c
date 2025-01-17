/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack_elements.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 23:30:40 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 22:36:55 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_stack_elements(t_list **stack_a)
{
	t_list	*current;
	t_list	*min_node;
	int		current_index;

	if (!stack_a || !(*stack_a))
		return ;
	current_index = 0;
	while (*stack_a)
	{
		current = *stack_a;
		min_node = NULL;
		while (current)
		{
			if ((min_node == NULL || current->data < min_node->data)
				&& current->index == -1)
				min_node = current;
			current = current->next;
		}
		if (!min_node)
			break ;
		min_node->index = current_index;
		current_index++;
	}
}
