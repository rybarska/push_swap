/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:34:23 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 21:34:25 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_list **list)
{
	t_list	*last;
	t_list	*second_last;

	if (!*list || !(*list)->next)
		return ;
	last = *list;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *list;
	*list = last;
}

void	rra(t_list **a)
{
	rev_rot(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rev_rot(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	if (*a)
		rev_rot(a);
	if (*b)
		rev_rot(b);
	write(1, "rrr\n", 4);
}
