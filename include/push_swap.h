/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:58:52 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/11 17:58:55 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"

/*maximum length for integer string starting with a sign*/
# define MAX_LENGTH	11
# define MAX_INT	+2147483647
# define MIN_INT	-2147483648

/* clean exit */
//void	clean_up(t_list **a, t_list **b);
void	free_array(char **array);
void	snuff_it(t_list **a, t_list **b, char **input, char *str_msg);
void	exit_like_a_boss(t_list **a, t_list **b);
/* args */
char	**format_input(int argc, char **argv, char	**input);
/* lists */
void	set_stacks(t_list **a, t_list **b, char **input);
void	set_indexes(t_list **list);
int		set_num(char *numstr, t_list **a, t_list **b, char **input);
/* sorts */
void	sort_small(t_list **a, t_list **b);
bool	is_sorted(t_list *list);
void	sort_three(t_list **a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	do_radix_sort(t_list **a, t_list **b);
/* utils */
int		find_distance_to_min(t_list **list, int bingo);
int		find_min_index(t_list *list);
int		find_max_index(t_list *list);
void	put_list_nums(t_list *list);
void	put_list_indexes(t_list *list);
/* operations */
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
