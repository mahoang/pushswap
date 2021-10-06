/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:27:00 by zephyrus          #+#    #+#             */
/*   Updated: 2021/10/06 05:17:15 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_first	do_algo(t_first *a)
{
	t_first	*b;

	b = init_list();
	check_list(a);
	push(a, b);
	free_list(b);
	return (*a);
}

t_first	algo_false(t_first *stack)
{
	t_first	*temp;
	t_stack	*son;
	int		value;

	value = INT_MIN;
	temp = stack;
	son = temp->first;
	//check_list(temp);
		printf("------\n");

	while (is_sort(temp) == 0)
	{
		if (son->nxt == NULL)
			son = temp->first;
		if (son->val > son->nxt->val)
		{
			value = son->val;
			son->val = son->nxt->val;
			son->nxt->val = value;
		}
		son = son->nxt;
	}
	//check_list(temp);
	check_list(stack);
	return (*temp);
}

int	get_median(t_first	*f_list, int len)
{
	t_stack	*f_stack;
	int		i;

	f_stack = f_list->first;
	i = 1;
	if (len % 2 == 0)
	{
		while (i++ < len / 2)
			f_stack = f_stack->nxt;
		//printf("mediane %i\n", (f_stack->val + f_stack->nxt->val) / 2);
		return ((f_stack->val + f_stack->nxt->val) / 2);
	}
	i = 0;
	while (i++ < (len / 2))
		f_stack = f_stack->nxt;
	//printf("mediane %i\n", f_stack->val);
	return (f_stack->val);
}

int	get_decile(t_first *f_list, int len, int decile)
{
	t_stack	*f_stack;
	int		i;

	f_stack = f_list->first;
	i = 1;
	//printf("len%i\n", len);
	if (len % 2 == 0)
	{
		while (i++ < len * decile / 10)
			f_stack = f_stack->nxt;
		//printf("decile %i\n", (f_stack->val + f_stack->nxt->val) / 2);
		return ((f_stack->val + f_stack->nxt->val) / 2);
	}
	i = 0;
	while (i++ < (len * decile / 10))
		f_stack = f_stack->nxt;
	//printf("decile %i\n", f_stack->val);
	return (f_stack->val);
}
