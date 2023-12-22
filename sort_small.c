/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:27:47 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/16 19:27:51 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *list)
{
	t_list	*current;
	t_list	*next;

	if (!list)
		return (true);
	while (list->next)
	{
		current = list;
		next = list->next;
		if (current->num > next->num)
			return (false);
		list = list->next;
	}
	return (true);
}

void	sort_three(t_list **a)
{
	int		max_value;
	t_list	*max_node;
	t_list	*current;

	if (!*a || !(*a)->next)
		return ;
	max_value = MIN_INT;
	max_node = NULL;
	current = *a;
	while (current)
	{
		if (current->num > max_value)
		{
			max_value = current->num;
			max_node = current;
		}
		current = current->next;
	}
	current = *a;
	if (current == max_node)
		ra(a);
	else if (current->next == max_node)
		rra(a);
	if (*a && (*a)->next && (*a)->num > (*a)->next->num)
		sa(a);
}

void	sort_four(t_list **a, t_list **b)
{
	int	distance;

	distance = find_distance_to_min(a, find_min_index(*a));
	if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 1)
		ra(a);
	else if (distance == 3)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_list **a, t_list **b)
{
	int	distance;

	distance = find_distance_to_min(a, find_min_index(*a));
	if (distance == 4)
		rra(a);
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance >= 1)
	{
		if (distance == 2)
			ra(a);
		ra(a);
	}
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_small(t_list **a, t_list **b)
{
	if (is_sorted(*a))
		return ;
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
}
