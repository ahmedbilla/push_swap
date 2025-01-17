/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:53:22 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/11 23:21:23 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*search_min_number(t_list *a)
{
	t_list	*min_number;
	t_list	*current;

	min_number = a;
	current = a;
	while (current != NULL)
	{
		if (current->data < min_number->data)
			min_number = current;
		current = current->next;
	}
	return (min_number);
}
