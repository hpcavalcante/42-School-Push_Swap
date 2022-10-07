/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:41:42 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 19:01:38 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack {
	
	int		*data;
	int 	top;
	int		size;
	int		capacity;

} t_stack;

t_stack		*init_stack_a(t_stack *stack_a, int argc, char **argv);
t_stack		*init_stack_b(t_stack *stack_b, int argc);
int			is_sorted(t_stack *stack_a);
int			reverse_sorted(t_stack *stack);
int			get_max(t_stack *stack_a);
int			get_min(t_stack *stack_a);
int			only_numbers(int argc, char **argv);
int			duplicate(int argc, char **argv);
int			amount_digits(char *argv);
int			*sort_stack(t_stack *stack);
void		validate(t_stack *stack_a, int argc, char **argv);
void		free_all(t_stack *stack);
void		fill_stack(t_stack *stack_a, char **argv);
void		error(t_stack *stack);
void		simple_sort(t_stack *stack_a);
void		middle_sort(t_stack *stack_a, t_stack *stack_b);
void		push_swap(t_stack *stack_a, t_stack *stack_b, int argc);
void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

#endif