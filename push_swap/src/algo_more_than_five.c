/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_more_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:43:46 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/14 20:43:52 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_position(t_list *list, t_list *node)
{
	int		position;
	t_list	*current;

	position = 0;
	current = list;
	while (current != NULL && current != node)
	{
		position++;
		current = current->next;
	}
	return (position);
}

void	check_more_five(t_list **a, t_list **b)
{
	int		position;
	t_list	*max_node;
	int		size;

	if (!b || !(*b))
		return ;
	*a = NULL;
	size = list_size(*b);
	while (size)
	{
		max_node = search_max_number(*b);
		position = 0;
		position = get_position(*b, max_node);
		if (position <= (size / 2))
		{
			while (position-- != 0)
				rotate(b, 2);
		}
		else
			while (position++ != size)
				reverse(b, 2);
		push(a, b, 1);
		size--;
	}
}
