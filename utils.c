/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:00:28 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 22:00:32 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_distance_to_min(t_list **list, int bingo)
{
	int		distance;
	t_list	*current;

	distance = 0;
	current = *list;
	while (current != NULL)
	{
		if (current->index == bingo)
			return (distance);
		current = current->next;
		distance++;
	}
	return (0);
}

int	find_min_index(t_list *list)
{
	int	min;

	min = MAX_INT;
	while (list != NULL)
	{
		if (min > list->index)
			min = list->index;
		list = list->next;
	}
	if (min == MAX_INT)
		return (-1);
	else
		return (min);
}

int	find_max_index(t_list *list)
{
	int	max;

	max = -1;
	while (list)
	{
		if (max < list->index)
			max = list->index;
		list = list->next;
	}
	return (max);
}

void	put_list_nums(t_list *list)
{
	t_list	*current;
	int		fd;

	current = list;
	fd = 1;
	while (current)
	{
		ft_putnbr_fd(current->num, fd);
		write(1, "\n", 1);
		current = current->next;
	}
}

void	put_list_indexes(t_list *list)
{
	t_list	*current;
	int		fd;

	current = list;
	fd = 1;
	while (current)
	{
		ft_putnbr_fd(current->index, fd);
		write(1, "\n", 1);
		current = current->next;
	}
}
