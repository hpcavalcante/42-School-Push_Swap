/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 19:21:04 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 12:47:30 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack_a(t_stack *stack_a, int argc, char **argv)
{
	stack_a = ft_calloc(sizeof(t_stack), 1);
	stack_a->data = (int *)ft_calloc(sizeof(int), argc);
	stack_a->top = argc - 2;
	stack_a->size = argc - 1;
	stack_a->capacity = argc - 1;
	fill_stack(stack_a, argv);
	validate(stack_a, argc - 1, argv + 1);
	return (stack_a);
}

t_stack	*init_stack_b(t_stack *stack_b, int argc)
{
	stack_b = ft_calloc(sizeof(t_stack), 1);
	stack_b->data = (int *)ft_calloc(sizeof(int), argc);
	stack_b->top = -1;
	stack_b->size = 0;
	stack_b->capacity = argc - 1;
	return (stack_b);
}
