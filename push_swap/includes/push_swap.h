/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbilla <ahbilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:17:29 by ahbilla           #+#    #+#             */
/*   Updated: 2025/01/15 21:01:17 by ahbilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

long	ft_atoi(char *str);
int		is_numeric(const char *str);
int		process_arguments(int ac, char *av[]);
char	**ft_split(char const *s, char c);
typedef struct node
{
	int			index;
	int			data;
	struct node	*next;
}	t_list;
int		has_duplicate(t_list *head);
void	append_node(t_list **head, int num);
t_list	*create_node(int num);
void	free_list(t_list *head);
void	swap(t_list **head, int index);
void	check_compare(t_list *head);
void	check_compare_three(t_list **head);
void	rotate(t_list **head_a, int i);
void	reverse(t_list **head_a, int i);
void	reverse(t_list **head_a, int i);
void	push(t_list **head_a, t_list **head_b, int flag);
t_list	*search_min_number(t_list *a);
t_list	*search_max_number(t_list *a);
void	check_compare_four(t_list **a, t_list **b);
int		is_sorted(t_list *a);
void	check_compare_five(t_list **a, t_list **b);
int		list_size(t_list *lst);
void	index_stack_elements(t_list **stack_a);
void	sort_utils(t_list **a, t_list **b);
void	check_more_five(t_list **a, t_list **b);

#endif