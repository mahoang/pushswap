/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:14:19 by mahoang           #+#    #+#             */
/*   Updated: 2021/09/18 13:52:42 by zephyrus         ###   ########.fr       */
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
void	erase_first(t_first *stack)
{
	t_stack	*tmp;

	if(stack->first != NULL)
	{
		tmp = stack->first;
		stack->first = stack->first->nxt;
		free(tmp);
	}
}
