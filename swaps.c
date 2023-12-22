/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:26:21 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 21:26:23 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void	sa(t_list **a)
{
	swap_first_two(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap_first_two(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap_first_two(a);
	swap_first_two(b);
	write(1, "ss\n", 3);
}
