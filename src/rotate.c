/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:15:10 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:44:15 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack_a)
{
	int	temp;
	int	i;

	temp = stack_a->data[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	int	temp;
	int	i;

	temp = stack_b->data[stack_b->top];
	i = stack_b->top;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	i;

	temp = stack_a->data[stack_a->top];
	i = stack_a->top;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		i--;
	}
	stack_a->data[0] = temp;
	temp = stack_b->data[stack_b->top];
	i = stack_b->top;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		i--;
	}
	stack_b->data[0] = temp;
	write(1, "rr\n", 3);
}
