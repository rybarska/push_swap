/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:40:20 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/12 20:40:23 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = -1;
	if (array)
	{
		while (array[++i])
			free(array[i]);
		free(array);
	}
}

static void	free_list(t_list **list)
{
	t_list	*temp;
	t_list	*current;

	current = *list;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

static void	clean_up(t_list **a, t_list **b)
{
	if (a && *a)
		free_list(a);
	if (b && *b)
		free_list(a);
}

void	snuff_it(t_list **a, t_list **b, char **input, char *str_msg)
{
	free_array(input);
	clean_up(a, b);
	write(2, str_msg, ft_strlen(str_msg));
	exit(EXIT_FAILURE);
}

void	exit_like_a_boss(t_list **a, t_list **b)
{
	clean_up(a, b);
	exit(EXIT_SUCCESS);
}
