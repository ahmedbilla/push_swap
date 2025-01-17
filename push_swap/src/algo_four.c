/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:31:46 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/15 14:43:11 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_compare_four(t_list **a, t_list **b)
{
	t_list	*current;
	int		position;

	position = 1;
	if (is_sorted(*a))
		return ;
	current = *a;
	while (current != NULL)
	{
		if (current == search_min_number(*a) && position == 4)
		{
			reverse(a, 1);
			push(a, b, 2);
			check_compare_three(a);
			push(a, b, 1);
			return ;
		}
		current = current->next;
		position++;
	}
	while (*a != search_min_number(*a))
		rotate(a, 1);
	push(a, b, 2);
	check_compare_three(a);
	push(a, b, 1);
}
