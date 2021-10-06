/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 00:27:00 by zephyrus          #+#    #+#             */
/*   Updated: 2021/10/06 04:14:12 by zephyrus         ###   ########.fr       */
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

t_stack	algo_temp(t_first *stack)
{
	t_first	*temp;
	t_stack	*son;
	int		value;

	value = INT_MIN;
	temp = stack;
	son = temp->first;
	check_list(temp);
		printf("------\n");

	while (is_sort(stack) == 0)
	{
		if (son->nxt == NULL)
			son = temp->first;
		if (son->val > son->nxt->val)
		{
			value = son->val;
			son->val = son->nxt->val;
			son->nxt->val = value;
			check_list(temp);

		}
		son = son->nxt;
		//sleep(1);
		printf("1\n");
	}
	//check_list(temp);
	//check_list(stack);
	return (*son);
}

