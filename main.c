/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:33 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/22 13:50:09 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_first	*init_list(void)
{
	t_stack	*empstack;
	t_first	*first;

	empstack = malloc(sizeof(t_stack));
	first = malloc(sizeof(t_first));
	if (empstack && first)
	{
		empstack->val = 0;
		empstack->nxt = NULL;
		first->first = empstack;
	}
	return (first);
}

void	free_list(t_first *lst)
{
	t_stack	*tmp;

	if (lst == NULL)
		exit(EXIT_FAILURE);
	tmp = lst->first;
	while (tmp != NULL)
	{
		tmp = lst->first->nxt;
		free (lst->first);
		lst->first = tmp;
	}
	free (lst);
}

int	is_sort(t_first *lst)
{
	t_stack	*sort;

	sort = lst->first;
	while (sort->nxt->val != 0 && sort->val < sort->nxt->val)
	{
		printf("compare sort->val %i et nxt %i\n", sort->val, sort->nxt->val);
		sort = sort->nxt;
	}
	if (sort->nxt->val == 0)
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_first	*stack;
	t_first	*b;

	stack = init_list();
	if (stack && fill_lst(stack, ac - 1, av + 1))
	{
		check_list(stack);
		printf("len %i\n",count_chain(stack));
		if (is_sort(stack))
		{
			b = init_list();

			//push(stack, b);
			//check_list(b);
			del_last(stack, count_chain(stack));
			check_list(stack);

			rotate(stack, count_chain(stack));
			check_list(stack);
			r_rotate(stack, count_chain(stack));
			check_list(stack);

			//swap(stack);
			free_list(stack);
			free_list(b);
			return (0);
			//do smthg begin work
		}
		else
			printf("a stack in order\n");
	}
	else if (ac != 1)
	{
		write (1, "Error\n", 7);
		free_list (stack);
		return (-1);
	}
	printf("bla\n");
	free_list(stack);
	return (0);
}
