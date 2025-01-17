/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:07:58 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 22:41:51 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse(t_list **head_a, int i)
{
	t_list	*prev;
	t_list	*curr;

	prev = NULL;
	curr = *head_a;
	if (!head_a || !(*head_a) || !((*head_a)->next))
		return ;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *head_a;
	*head_a = curr;
	if (i == 1)
		write(1, "rra\n", 4);
	else if (i == 2)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **head_rra, t_list **head_rrb)
{
	if (!head_rra || !(*head_rra) || !((*head_rra)->next)
		|| !head_rrb || !(*head_rrb) || !((*head_rrb)->next))
		return ;
	reverse(head_rra, 0);
	reverse(head_rrb, 0);
	write(1, "rrr\n", 4);
}
