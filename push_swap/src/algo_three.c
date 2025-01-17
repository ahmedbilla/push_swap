/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:40:15 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 22:03:40 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_condtion_one(t_list **head, t_list *first,
						t_list *second, t_list *third)
{
	if (first->data > second->data && first->data > third->data
		&& second->data < third->data)
		rotate(head, 1);
	else if (first->data < second->data && first->data > third->data)
		reverse(head, 1);
	else if (first->data > second->data && first->data > third->data
		&& second->data > third->data)
	{
		rotate(head, 1);
		swap(head, 1);
	}
	else if (first->data > second->data && first->data < third->data)
		swap(head, 1);
}

void	check_compare_three(t_list **head)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!head || !(*head) || !((*head)->next) || !((*head)->next->next))
		return ;
	first = *head;
	second = (*head)->next;
	third = (*head)->next->next;
	check_condtion_one(head, first, second, third);
	if (second->data < first->data && second->data > third->data)
	{
		reverse(head, 1);
		swap(head, 1);
	}
	else if (second->data > first->data && second->data > third->data
		&& third->data > first->data)
	{
		reverse(head, 1);
		swap(head, 1);
	}
	else
		return ;
}
