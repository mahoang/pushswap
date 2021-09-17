/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahoang <mahoang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:51 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/18 00:35:29 by mahoang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*nxt;
}				t_stack;

int	ft_strlen(char *str);
int fill_lst(t_stack *stack, int ac, char **av);
void	push(t_stack *stacka, t_stack *stackb);
void	swap(t_stack *stack);
void	check_list(t_stack *stack);
t_stack	*erase_first(t_stack *stack);

#endif
