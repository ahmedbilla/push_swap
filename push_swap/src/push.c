/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:11:59 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 22:39:31 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_list **head_a, t_list **head_b, int flag)
{
	t_list	*temp;

	if (flag == 2)
	{
		temp = *head_a;
		if (!*head_a)
			return ;
		*head_a = (*head_a)->next;
		temp->next = *head_b;
		*head_b = temp;
		write(1, "pb\n", 3);
	}
	else if (flag == 1)
	{
		if (!*head_b)
			return ;
		temp = *head_b;
		*head_b = (*head_b)->next;
		temp->next = *head_a;
		*head_a = temp;
		write(1, "pa\n", 3);
	}
}
