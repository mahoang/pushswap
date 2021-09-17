/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:33 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/10 18:22:01 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*
**sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
**is only one or no elements).
**sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
**is only one or no elements).
**ss : sa and sb at the same time.
**pa : push a - take the first element at the top of b and put it at the top of a. Do
**nothing if b is empty.
**pb : push b - take the first element at the top of a and put it at the top of b. Do
**nothing if a is empty.
**ra : rotate a - shift up all elements of stack a by 1. The first element becomes
**the last one.
**rb : rotate b - shift up all elements of stack b by 1. The first element becomes
**the last one.
**rr : ra and rb at the same time.
**rra : reverse rotate a - shift down all elements of stack a by 1. The last element
**becomes the first one.
*/
t_stack	*init_list(void)
{
	t_stack *empstack;

	empstack = malloc(sizeof(t_stack));
	if (empstack)
	{
		empstack->val = 0;
		empstack->prv = empstack;
		empstack->nxt = empstack;
	}
	return (empstack);
}

void	free_list(t_stack *lst)
{
	t_stack *current;
	t_stack *next;

	if (lst == NULL)
		return;
	current = lst->nxt;
	next = current->nxt;
	while (current != next)
	{
		//free (current);
		current = next;
		next = next->nxt;
	}
	free (lst);
}

int	is_sort(t_stack *lst)
{
	t_stack *sort;

	sort = lst->nxt;
	while (sort->val < sort->nxt->val)
		sort = sort->nxt;
	if (sort->nxt == lst)
		return (1);
	return (0);
}
int	main(int ac, char *av[])
{
	t_stack *stack;

	stack = init_list();

	if (stack && fill_lst(stack, ac - 1, av + 1))
	{
		if (is_sort(stack) == 0)
		{
			swap(stack);
			printf("\ntest\n");
			return (0);
			//do smthg begin work
		}
	}
	else if (ac != 1)
	{
		write (1, "Error\n", 7);
		//free_list (stack);
		return (-1);
	}
	free_list(stack);
	return (0);
}
