/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:51:54 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 22:43:42 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **head_a, int i)
{
	t_list	*temp;
	t_list	*newhead;

	if (!head_a || !(*head_a) || !((*head_a)->next))
		return ;
	temp = *head_a;
	newhead = *head_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	*head_a = (*head_a)->next;
	temp->next = newhead;
	newhead->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
	else if (i == 2)
		write(1, "rb\n", 3);
}

void	rr(t_list **head_ra, t_list **head_rb)
{
	if (!head_ra || !(*head_ra) || !((*head_ra)->next)
		|| !head_rb || !(*head_rb) || !((*head_rb)->next))
		return ;
	rotate(head_ra, 0);
	rotate(head_rb, 0);
	write(1, "rr", 2);
}
