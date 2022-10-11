/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:48:53 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:33:57 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a)
{
	int	temp;

	temp = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b)
{
	int	temp;

	temp = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	temp = stack_a->data[stack_a->top];
	stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
	stack_a->data[stack_a->top - 1] = temp;
	temp = stack_b->data[stack_b->top];
	stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
	stack_b->data[stack_b->top - 1] = temp;
	write(1, "ss\n", 3);
}
