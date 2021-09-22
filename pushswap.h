/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zephyrus <zephyrus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:17:51 by zephyrus          #+#    #+#             */
/*   Updated: 2021/09/22 14:54:34 by zephyrus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

# define SA	11
# define SB	12
# define SS	13
# define PA	21
# define PB	22
# define RA	31
# define RB	32
# define RR	33
# define RRA	41
# define RRB	42
# define RRR	43

typedef struct s_stack
{
	int				val;
	struct s_stack	*nxt;
}				t_stack;

typedef struct s_first
{
	struct s_stack		*first;
}				t_first;

int		ft_strlen(char *str);
int		fill_lst(t_first *stack, int ac, char **av);
void	push(t_first *from, t_first *to);
void	swap(t_first *stack);
void	rotate(t_first *stack, int len);
void	r_rotate(t_first *stack, int len);
void	check_list(t_first *stack);
void	del_first(t_first *stack);
void	del_last(t_first *stack, int len);
int		count_chain(t_first *stack);
int	have_duplicates(t_first *stack, int len);

#endif
