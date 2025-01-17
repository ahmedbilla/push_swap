/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:27:12 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/15 15:49:11 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_range(int nb_nodes)
{
	if (nb_nodes > 100)
		return (33);
	else
		return (16);
}

int	detect_comb(t_list **head_a, int size)
{
	int		diff;
	int		count;
	t_list	*tmp;

	tmp = *head_a;
	count = 0;
	while (tmp && tmp->next)
	{
		diff = tmp->index - tmp->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		tmp = tmp->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

void	sort_utils(t_list **a, t_list **b)
{
	t_list	*temp;
	int		i;

	if (!a || !*a)
		return ;
	i = 0;
	while (*a)
	{
		temp = *a;
		if (temp->index <= i)
		{
			push(a, b, 2);
			i++;
		}
		else if (temp->index < (i + ft_range(list_size(*a))))
		{
			push(a, b, 2);
			rotate(b, 2);
			i++;
		}
		else if (detect_comb(a, list_size((*a))))
			reverse(a, 1);
		else
			rotate(a, 1);
	}
}
