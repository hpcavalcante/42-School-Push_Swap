/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:57:07 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:47:39 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top++;
	stack_a->data[stack_a->top] = stack_b->data[stack_b->top];
	stack_b->top--;
	stack_a->size++;
	stack_b->size--;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->top++;
	stack_b->data[stack_b->top] = stack_a->data[stack_a->top];
	stack_a->top--;
	stack_a->size--;
	stack_b->size++;
	write(1, "pb\n", 3);
}
