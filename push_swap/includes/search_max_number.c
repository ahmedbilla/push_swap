/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_max_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 22:07:03 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/11 23:20:03 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*search_max_number(t_list *a)
{
	t_list	*max_number;
	t_list	*current;

	max_number = a;
	current = a;
	while (current != NULL)
	{
		if (current->data > max_number->data)
			max_number = current;
		current = current->next;
	}
	return (max_number);
}
