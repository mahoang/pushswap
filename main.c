/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:33 by zephyrus          #+#    #+#             */
/*   Updated: 2021/10/06 03:54:33 by zephyrus         ###   ########.fr       */
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

int	main(int ac, char *av[])
{
	t_first	*stack;

	stack = init_list();
	if (stack && fill_lst(stack, ac - 1, av + 1))
	{
		del_last(stack, count_chain(stack));
		algo_temp(stack);
		return(0);
		//check_list(stack);
		printf("len %i\n",count_chain(stack));
		if (is_sort(stack) && !have_duplicates(stack, count_chain(stack), 0, 0))
		{
			do_algo(stack);

			//swap(stack);
			free_list(stack);
			return (0);
			//do smthg begin work
		}
		else
			printf("a stack in order or have dup\n");
	}
	else if (ac != 1)
	{
		write (1, "Error\n", 7);
		free_list (stack);
		return (-1);
	}
	printf("end\n");
	free_list(stack);
	return (0);
}
