/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:51 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/18 14:39:09 by zephyrus         ###   ########.fr       */
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

typedef struct s_first
{
	struct s_stack		*first;
}				t_first;

int	ft_strlen(char *str);
int fill_lst(t_first *stack, int ac, char **av);
void	push(t_first *from, t_first *to);
void	swap(t_first *stack);
void	check_list(t_first *stack);
void	erase_first(t_first *stack);

#endif
