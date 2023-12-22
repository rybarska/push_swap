/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:49:53 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/11 17:49:56 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	print_list(t_list *list)
{
	t_list		*current;

	current = list;
	while (current)
	{
		ft_putnbr_fd(current->num, 1);
		ft_putchar_fd(' ', 1);
		current = current->next;
	}
	printf("\n");
}*/

static char	**ft_strdup_argv_array(char **src_array)
{
	int		i;
	char	**dest_array;

	i = 0;
	while (src_array[i])
		i++;
	dest_array = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dest_array)
		return (NULL);
	i = 0;
	while (src_array[i])
	{
		dest_array[i] = ft_strdup(src_array[i]);
		if (!dest_array[i])
		{
			free_array(dest_array);
			return (NULL);
		}
		i++;
	}
	dest_array[i] = NULL;
	return (dest_array);
}

char	**format_input(int argc, char **argv, char	**input)
{
	if (argc == 2)
	{
		input = ft_split(argv[1], ' ');
		if (!input)
			return (NULL);
	}
	else if (argc > 2)
	{
		input = ft_strdup_argv_array(argv + 1);
		if (!input)
			return (NULL);
	}
	return (input);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**input;

	a = NULL;
	b = NULL;
	input = NULL;
	if (argc > 1 && argv[1][0])
	{
		input = format_input(argc, argv, input);
		if (!input)
			snuff_it(&a, &b, input, "Error splitting arguments");
		set_stacks(&a, &b, input);
		free_array(input);
		set_indexes(&a);
		if (ft_lstsize(a) <= 5)
			sort_small(&a, &b);
		else
			do_radix_sort(&a, &b);
		exit_like_a_boss(&a, &b);
		return (0);
	}
	else
		return (1);
}
