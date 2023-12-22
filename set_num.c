/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:34:21 by arybarsk          #+#    #+#             */
/*   Updated: 2023/12/17 16:34:25 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_overflow(char *numstr)
{
	int	result;
	int	digit;
	int	sign;

	result = 0;
	sign = 1;
	if (!numstr || *numstr == '\0')
		return (1);
	if (numstr[0] == '-')
		sign = -1;
	if (*numstr == '+' || *numstr == '-')
		numstr++;
	while (*numstr != '\0')
	{
		digit = *numstr - '0';
		if ((sign == 1) && ((result > MAX_INT / 10)
				|| (result >= MAX_INT / 10 && digit > MAX_INT % 10)))
			return (1);
		else if ((sign == -1) && ((result < MIN_INT / 10)
				|| (result <= MIN_INT / 10 && digit > -(MIN_INT % 10))))
			return (1);
		result = result * 10 + sign * digit;
		numstr++;
	}
	return (0);
}

static int	is_not_numeric(char *numstr)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (numstr[i] && ft_iswhitespace(&numstr[i]))
		++i;
	if (numstr[i] == '\0')
		return (1);
	if (numstr[i] == '-' || numstr[i] == '+')
	{
		if (numstr[i] == '-')
			sign = -1;
		i++;
	}
	if (numstr[i] == '\0')
		return (1);
	while (numstr[i] == '0')
		i++;
	while (numstr[i] >= '0' && numstr[i] <= '9')
		i++;
	if (numstr[i] != '\0')
		return (1);
	return (0);
}

int	set_num(char *numstr, t_list **a, t_list **b, char **input)
{
	int	num;

	num = 0;
	if (is_overflow(numstr))
		snuff_it(a, b, input, "Error: invalid input");
	if (is_not_numeric(numstr))
		snuff_it(a, b, input, "Error: invalid input");
	num = ft_atoi(numstr);
	return (num);
}
