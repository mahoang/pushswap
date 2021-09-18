/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:14:19 by mahoang           #+#    #+#             */
/*   Updated: 2021/09/18 15:41:54 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_list(t_first *stack)
{
	int	i;
	t_stack *check;

	i = 0;
	check = stack->first;
	while (check != NULL)
	{
		printf("element num %i de la liste, val = %i\n", i, check->val);
		check = check->nxt;
		//printf("check %i\n", check->val);
		i++;
	}
}
/*
t_stack	*add_first(t_stack *stack, int value)
{

}
*/
void	del_first(t_first *stack)
{
	t_stack	*tmp;

	if(stack->first != NULL)
	{
		tmp = stack->first;
		stack->first = stack->first->nxt;
		free(tmp);
	}
}

void	del_last(t_first *stack, int len)
{
	t_stack *tmp;
	t_stack *n_last;
	int		i;

	tmp = stack->first;
	//printf("stack first elem -- %i \n", tmp->val);

	i = 0;
	while((i < len - 2) && tmp->nxt != NULL )
	{
		tmp = tmp->nxt;
		i++;
	}
	n_last = tmp->nxt;
	tmp->nxt = NULL;
	free(n_last);
	//printf("stack last elem %i \n", tmp->val);
}

int		count_chain(t_first *stack)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = stack->first;
	if (stack->first == NULL)
		return (0);
	while (tmp->nxt != NULL)
	{
		tmp = tmp->nxt;
		i++;
	}
	i++;
	return (i);
}
