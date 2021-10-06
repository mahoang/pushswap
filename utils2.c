/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:38:06 by zephyrus          #+#    #+#             */
/*   Updated: 2021/10/06 00:23:41 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**i and j at 0 when called/norm
*/
int	have_duplicates(t_first *stack, int len, int i, int j)
{
	int		*dup;
	t_stack	*tmp;

	tmp = stack->first;
	dup = malloc (sizeof(int) * len);
	while (i < len)
	{
		dup[i] = tmp->val;
		i++;
		tmp = tmp->nxt;
	}
	i = j + 1;
	while (j < len)
	{
		while (i < len)
		{
			if (dup[j] == dup[i])
				return (1);
			i++;
		}
		j++;
		i = j + 1;
	}
	free(dup);
	return (0);
}

int	list_max(t_first *stack)
{
	int		i;
	t_stack	*test;

	i = INT_MIN;
	test = stack->first;
	while (test != NULL)
	{
		if (test->val > i)
			i = test->val;
		test = test->nxt;
	}
	//printf("max val %i\n", i);
	return (i);
}

int	list_min(t_first *stack)
{
	int		i;
	t_stack	*test;

	i = INT_MAX;
	test = stack->first;
	while (test != NULL)
	{
		if (test->val < i)
			i = test->val;
		test = test->nxt;
	}
	//printf("min val %i\n", i);
	return (i);
}
