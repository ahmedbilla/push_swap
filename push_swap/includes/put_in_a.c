/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:00:09 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/11 23:58:41 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int num)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = num;
	new_node->next = NULL;
	new_node->index = -1;
	return (new_node);
}

void	append_node(t_list **head, int num)
{
	t_list	*new_node;
	t_list	*temp;

	new_node = create_node(num);
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	free_list(t_list *head)
{
	t_list	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
