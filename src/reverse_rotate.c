/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:35:34 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:34:29 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *stack_a)
{
	int	temp;
	int	i;

	temp = stack_a->data[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->top] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	int	temp;
	int	i;

	temp = stack_b->data[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->top] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	temp = stack_a->data[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->data[i] = stack_a->data[i + 1];
		i++;
	}
	stack_a->data[stack_a->top] = temp;
	temp = stack_b->data[0];
	i = stack_b->top;
	while (i < stack_b->top)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		i++;
	}
	stack_b->data[stack_b->top] = temp;
	write(1, "rrr\n", 4);
}
