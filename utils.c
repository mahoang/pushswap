/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:14:19 by mahoang           #+#    #+#             */
/*   Updated: 2021/09/18 00:46:54 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		printf("element num %i de la liste, val = %i\n", i, stack->val);
		stack = stack->nxt;
		i++;
	}
}
/*
t_stack	*add_first(t_stack *stack, int value)
{

}
*/
t_stack	*erase_first(t_stack *stack)
{
	t_stack	*tmp;

	if(stack != NULL)
	{
		tmp = stack->nxt;
		free(stack);
		return (tmp);
	}
	return (NULL);
}
