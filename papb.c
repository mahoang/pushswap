/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:00:42 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/17 23:36:40 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


/*
**pa : push a - take the first element at the top of b and put it at the top of a. Do
**nothing if b is empty.
**pb : push b - take the first element at the top of a and put it at the top of b. Do
**nothing if a is empty.
*/

void	push(t_stack *stacka, t_stack *stackb)
{
	t_stack	*push;
	t_stack	*topa;
	t_stack *topb;

	push = stacka->nxt;
	topa = push->nxt;
	topb = stackb->nxt;
	if (push != stacka)
	{
		stacka->nxt = topb;
		topa->prv = stacka;
		stackb->nxt = push;
		topb->prv = push;
		push->prv = stackb;
		push->nxt = topb;
	}
	stacka->val--;
	stackb->val++;
	printf("\nstackaval %i\n", stacka->val);
	printf("\nstackbval %i\n", stackb->val);
}

void	swap(t_stack *stack)
{
	int a;

	a = stack->val;
	stack->val = stack->nxt->val;
	stack->nxt->val = a;

}
