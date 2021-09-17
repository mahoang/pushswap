/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:33 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/18 00:58:50 by mahoang          ###   ########.fr       */
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
		empstack->nxt = NULL;
	}
	return (empstack);
}

void	free_list(t_stack *lst)
{
	t_stack *tmp;

	while (lst != NULL)
	{
		tmp = lst->nxt;
		//free (lst);
		lst = tmp;
	}
	//free (lst);
}

int	is_sort(t_stack *lst)
{
	t_stack *sort;


	sort = lst->nxt;
	printf("list val %i\n", lst->val);
	printf("sort val %i\n", sort->val);
	while (sort != NULL && sort->val < sort->nxt->val)
	{
		printf("aqacccccc%i\n", sort->val);
		sort = sort->nxt;
	}
	if (sort == NULL)
		return (1);
	return (0);
}
int	main(int ac, char *av[])
{
	t_stack *stack;

	stack = init_list();
	if (stack && fill_lst(stack, ac - 1, av + 1))
	{
		if (is_sort(stack) == 1)
		{
			check_list(stack);
			erase_first(stack);
			printf("\ntest\n");
			check_list(stack);
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
	printf("bla\n");
	free_list(stack);
	return (0);
}
