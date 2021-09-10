/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:37:05 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/10 17:10:42 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

long	get_nb(char *str)
{
	long l;
	int i;
	int s;

	l = 0;
	i = 0;
	s = 1;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i])
		l = l * 10 + str[i++] - '0';
	if (l > INT_MAX || l > INT_MAX)
		return (2147483647);
	return (l * s);
}

int	is_num(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-')
		str++;
//	printf("\nstr %s\n", str);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_stack	*new_list(t_stack *stack, int i)
{
	t_stack	*n_list;

	n_list = malloc(sizeof(t_stack));
	if (n_list)
	{
		n_list->val = i;
		n_list->prv = stack->prv;
		n_list->nxt = stack;
		stack->prv->nxt = n_list;
		stack->prv = n_list;
	}
	stack->val++;
	return (n_list);
}

int fill_lst(t_stack *stack, int ac, char **av)
{
	t_stack	*new;
	int		i;

	if (ac == 0)
		return (0);
	i = 0;
	while ( i < ac)
	{
		new = new_list(stack, get_nb(av[i]));
		if (!new || get_nb(av[i]) == 2147483647
			|| !is_num(av[i]))
			return (0);
		i++;
		printf("%d\n", new->val);
	}
	return (1);
}