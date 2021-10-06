/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:14:19 by mahoang           #+#    #+#             */
/*   Updated: 2021/10/06 04:13:46 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_list(t_first *stack)
{
	int		i;
	t_stack	*check;

	i = 0;
	check = stack->first;
	printf("\n");
	while (check != NULL)
	{
		printf("element num %i de la liste, val = %i\n", i, check->val);
		check = check->nxt;
		i++;
	}
}

void	del_first(t_first *stack)
{
	t_stack	*tmp;

	if (stack->first != NULL)
	{
		tmp = stack->first;
		stack->first = stack->first->nxt;
		free(tmp);
	}
}

void	del_last(t_first *stack, int len)
{
	t_stack	*tmp;
	t_stack	*n_last;
	int		i;

	tmp = stack->first;
	i = 0;
	while ((i < len - 2) && tmp->nxt != NULL )
	{
		tmp = tmp->nxt;
		i++;
	}
	n_last = tmp->nxt;
	tmp->nxt = NULL;
	free(n_last);
}

int	count_chain(t_first *stack)
{
	t_stack	*tmp;
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

int	is_sort(t_first *lst)
{
	t_stack	*sort;

	sort = lst->first;
	while (sort->nxt != NULL && sort->val < sort->nxt->val)
	{
		//printf("compare prec %i et suivant %i\n", sort->val, sort->nxt->val);
		sort = sort->nxt;
		printf("2\n");
	}
	if (sort->nxt == NULL)
	{
		printf("3\n");

		return (1);
	}
		printf("4\n");

	return (0);
}
