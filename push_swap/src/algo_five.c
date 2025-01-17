/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:13:59 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/15 15:43:17 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_compare_five(t_list **a, t_list **b)
{
	t_list	*current;
	int		position;

	if (is_sorted(*a))
		return ;
	current = *a;
	position = 1;
	while (current != NULL)
	{
		if (current == search_min_number(*a) && position == 5)
		{
			reverse(a, 1);
			push(a, b, 2);
			check_compare_four(a, b);
			push(a, b, 1);
			return ;
		}
		current = current->next;
		position++;
	}
	while (*a != search_min_number(*a))
		rotate(a, 1);
	push(a, b, 2);
	check_compare_four(a, b);
	push(a, b, 1);
}
