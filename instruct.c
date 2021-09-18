/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:00:42 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/18 15:57:03 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


/*
**pa : push a - take the first element at the top of b and put
 it at the top of a. Do
**nothing if b is empty.
**pb : push b - take the first element at the top of a and put it at the top of b. Do
**nothing if a is empty.
*/

void	push(t_first *from, t_first *to)
{
	t_stack *tmp;

	if (to != NULL)
	{
		tmp = malloc(sizeof(t_stack));
		//take top of from and put it on to
		tmp->val = from->first->val;
		tmp->nxt = to->first->nxt;
		to->first = tmp;
		//printf("1\n");

		//remove previous top of from
		del_first(from);
	}
}

void	swap(t_first *stack)
{
	int a;

	a = stack->first->val;
	stack->first->val = stack->first->nxt->val;
	stack->first->nxt->val = a;
}/*

void	rotate(t_first *stack)
{
	t_stack *tmp;
	t_stack *last;
	t_stack *first;

	first = stack->first;
	last = stack->first;
	tmp = stack->first;
	while (last->nxt != NULL)
		last = tmp->nxt;
	tmp = last;
	tmp->nxt =




}
*/
