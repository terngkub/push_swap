/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:14:10 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/06 09:18:17 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct		s_node
{
	int				n;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	size_t			len;
}					t_stack;

void				ft_error(void);

t_stack				*ft_stack_new(void);
t_stack				*ft_stack_push(t_stack *stack, t_node *node);
t_stack				*ft_stack_pushback(t_stack *stack, t_node *node);
t_node				*ft_node_new(int n);
t_node				*ft_stack_pop(t_stack *stack);

int					ft_stack_issorted(t_stack *stack);
void				ft_stack_print(t_stack *stack);

t_stack				*ft_stack_swap(t_stack *stack);
t_stack				*ft_stack_rotate(t_stack *stack);
t_stack				*ft_stack_revrotate(t_stack *stack);

void				ft_operate_s(char *op, t_stack *stack_a, t_stack *stack_b);
void				ft_operate_p(char *op, t_stack *stack_a, t_stack *stack_b);
void				ft_operate_r(char *op, t_stack *stack_a, t_stack *stack_b);
void				ft_operate(char *op, t_stack *stack_a, t_stack *stack_b,
						char print);

void				ft_check_duplication(t_stack *stack);
void				ft_check_input(char *str);
t_stack				*ft_read_input(int argc, char **argv);

void				ft_shortest_sort(t_stack *stack_a, t_stack *stack_b);

#endif
