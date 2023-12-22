/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:32:12 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 21:32:14 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*current;

	if (!*list || !(*list)->next)
		return ;
	first = *list;
	current = *list;
	while (current->next)
		current = current->next;
	current->next = first;
	*list = first->next;
	first->next = NULL;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	if (*a)
		rotate(a);
	if (*b)
		rotate(b);
	write(1, "rr\n", 3);
}
