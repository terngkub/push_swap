/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:14:10 by nkamolba          #+#    #+#             */
/*   Updated: 2017/12/07 19:10:03 by nkamolba         ###   ########.fr       */
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

t_stack				*ft_stack_new(void);
t_stack				*ft_stack_push(t_stack *stack, t_node *node);
t_stack				*ft_stack_pushback(t_stack *stack, t_node *node);
t_node				*ft_node_new(int n);
t_node				*ft_stack_pop(t_stack *stack);

t_stack				*ft_stack_swap(t_stack *stack);
t_stack				*ft_stack_rotate(t_stack *stack);
t_stack				*ft_stack_revrotate(t_stack *stack);

int					ft_stack_issorted(t_stack *stack);
void				ft_stack_print(t_stack *stack);
void				ft_debug(t_stack *stack_a, t_stack *stack_b);

void				ft_error(void);

void				ft_check_duplication(t_stack *stack);
void				ft_check_input(char *str);
t_stack				*ft_read_input(int argc, char **argv);

void				ft_operate_s(char *op, t_stack *stack_a, t_stack *stack_b);
void				ft_operate_p(char *op, t_stack *stack_a, t_stack *stack_b);
void				ft_operate_r(char *op, t_stack *stack_a, t_stack *stack_b);
void				ft_operate(char *op, t_stack *stack_a, t_stack *stack_b,
						char print);

typedef struct		s_op
{
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				arrange;
}					t_op;

void				ft_init_op(t_op *op);
void				ft_copy_op(t_op *dst, t_op *src);
void				ft_get_op_b(t_node *node_a, t_node *node_b, int len,
						t_op *op);
void				ft_get_op(t_stack *stack_a, t_stack *stack_b, t_op *op);
void				ft_run_op(t_stack *stack_a, t_stack *stack_b, t_op *op);

void				ft_optimize_rotate(t_op *op);
void				ft_optimize_revrotate(t_op *op);
void				ft_optimize_operation(t_op *op);

void				ft_stack_arrange(t_stack *stack_a, t_stack *stack_b);
void				ft_stack_arrange_add(t_stack *stack_b, t_op *op);

void				ft_three_sort(t_stack *stack_a, t_stack *stack_b);
void				ft_selection_sort(t_stack *stack_a, t_stack *stack_b,
						size_t len);
void				ft_short_sort(t_stack *stack_a, t_stack *stack_b);

#endif
