/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:08:42 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 21:08:45 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **list)
{
	t_list	*current;
	t_list	*min;

	current = *list;
	min = NULL;
	while (current)
	{
		if (current->index == -1 && (min == NULL || current->num < min->num))
			min = current;
		current = current->next;
	}
	return (min);
}

void	set_indexes(t_list **list)
{
	int		index;
	t_list	*current;

	index = 0;
	current = get_next_min(list);
	while (current)
	{
		current->index = index++;
		current = get_next_min(list);
	}
}

static int	has_duplicate(t_list **a, int num)
{
	t_list	*current;

	current = *a;
	while (current != NULL)
	{
		if (current->num && current->num == num)
			return (1);
		current = current->next;
	}
	return (0);
}

void	set_stacks(t_list **a, t_list **b, char **input)
{
	t_list		*node;
	int			num;
	int			i;

	i = 0;
	while (input[i])
	{
		node = NULL;
		num = -1;
		num = set_num(input[i], a, b, input);
		if (has_duplicate(a, num))
			snuff_it(a, b, input, "Error: found duplicate");
		node = (t_list *)malloc(sizeof(t_list));
		if (!node)
			snuff_it(a, b, input, "Error allocating memory");
		node->num = -1;
		node->num = num;
		node->index = -1;
		node->next = NULL;
		ft_lstadd_back(a, node);
		i++;
	}
	*b = NULL;
}
