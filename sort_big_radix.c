/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:13:12 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/18 21:13:14 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_required_bits(t_list *list)
{
	int		index_value;
	int		bit_count;

	bit_count = 0;
	while (list)
	{
		index_value = list->index;
		while (index_value >> bit_count != 0)
			bit_count++;
		list = list->next;
	}
	return (bit_count);
}

static void	run_a_step(t_list **a, t_list **b, int bit_position, int elements)
{
	t_list	*current;
	int		size_iter;

	current = *a;
	size_iter = 0;
	while (size_iter++ < elements)
	{
		current = *a;
		if (((current->index >> bit_position) & 1) == 1)
		{
			ra(a);
		}
		else
			pb(a, b);
	}
	while (ft_lstsize(*b) != 0)
		pa(a, b);
}

void	do_radix_sort(t_list **a, t_list **b)
{
	int	elements;
	int	required_bits;
	int	bit_position;

	if (is_sorted(*a))
		return ;
	elements = ft_lstsize(*a);
	required_bits = count_required_bits(*a);
	bit_position = 0;
	while (bit_position < required_bits)
	{
		run_a_step(a, b, bit_position, elements);
		bit_position++;
	}
}
