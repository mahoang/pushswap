/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:00:42 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/22 14:57:19 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
**take top of from and put it on to
**remove previous top of from
*/
void	push(t_first *from, t_first *to)
{
	t_stack	*tmp;

	if (to != NULL)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->val = from->first->val;
		tmp->nxt = to->first->nxt;
		to->first = tmp;
		del_first(from);
	}
}

void	swap(t_first *stack)
{
	int	a;

	a = stack->first->val;
	stack->first->val = stack->first->nxt->val;
	stack->first->nxt->val = a;
}

void	rotate(t_first *stack, int len)
{
	t_stack	*tmp;
	t_stack	*list;
	int		*rotate;
	int		i;

	i = 0;
	rotate = malloc(sizeof(int) * len);
	list = stack->first;
	tmp = stack->first;
	while (i < len)
	{
		rotate[i] = tmp->val;
		i++;
		tmp = tmp->nxt;
	}
	i = 1;
	while (i < len)
	{
		list->val = rotate[i];
		i++;
		list = list->nxt;
	}
	list->val = rotate[0];
	free(rotate);
}

void	r_rotate(t_first *stack, int len)
{
	t_stack	*tmp;
	t_stack	*list;
	int		*rr;
	int		i;

	i = 0;
	rr = malloc(sizeof(int) * len);
	list = stack->first;
	tmp = stack->first;
	while (i < len)
	{
		rr[i] = tmp->val;
		i++;
		tmp = tmp->nxt;
	}
	list->val = rr[len - 1];
	list = list->nxt;
	i = 0;
	while (i < len - 1)
	{
		list->val = rr[i];
		i++;
		list = list->nxt;
	}
	free(rr);
}

void	do_instr(int ope, t_first *astack, t_first *bstack)
{
	if ((ope == SA) || (ope == SS))
		swap(astack);
	if ((ope == SB) || (ope == SS))
		swap(bstack);
	if (ope == PA)
		push(bstack, astack);
	if (ope == PB)
		push(astack, bstack);
	if ((ope == RA) || (ope == RR))
		rotate(astack, count_chain(astack));
	if ((ope == RB) || (ope == RR))
		rotate(bstack, count_chain(bstack));
	if ((ope == RRA) || (ope == RRR))
		r_rotate(astack, count_chain(astack));
	if ((ope == RRB) || (ope == RRR))
		r_rotate(astack, count_chain(bstack));
}
