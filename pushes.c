/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:29:11 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 21:29:13 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dst, t_list **src)
{
	t_list	*head_src;

	if (*src != NULL)
	{
		head_src = *src;
		*src = (*src)->next;
		head_src->next = *dst;
		*dst = head_src;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
