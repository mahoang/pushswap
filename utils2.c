/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:38:06 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/22 14:58:19 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

{
	int *dup;
	int i;
	int j;
	t_stack	*tmp;

	tmp = stack->first;
	dup = malloc (sizeof(int) * len);
	i = 0;
	j = 0;
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
				return(1);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}
