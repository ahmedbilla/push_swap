/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:44:18 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/12 00:42:36 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_list *head)
{
	t_list	*current;
	t_list	*checker;

	current = head;
	while (current != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->data == checker->data)
			{
				return (1);
			}
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
