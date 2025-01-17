/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:31:22 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/15 15:51:35 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **head, int index)
{
	t_list	*temp;
	int		temp_data;
	int		i;

	temp = *head;
	i = 0;
	while (i < index)
	{
		if (temp->next != NULL)
		{
			temp_data = temp->data;
			temp->data = temp->next->data;
			temp->next->data = temp_data;
			temp = temp->next;
			i++;
		}
	}
	if (index == 1)
		write(1, "sa\n", 3);
	else if (index == 2)
		write(1, "sb\n", 3);
}

void	ss(t_list **head_sa, t_list **head_sb)
{
	if (!head_sa || !(*head_sa) || !((*head_sa)->next)
		|| !head_sb || !(*head_sb) || !((*head_sb)->next))
		return ;
	swap(head_sa, 0);
	swap(head_sb, 0);
}
