/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:32:21 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/09 14:51:08 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_list *lst)
{
	int		count;
	t_list	*head;

	head = lst;
	count = 1;
	if (!lst)
		return (0);
	while (head->next != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}
