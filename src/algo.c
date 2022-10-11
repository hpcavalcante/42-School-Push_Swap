/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:48:12 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:55:39 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_index(t_stack *stack, int data)
{
	int	index;

	index = 0;
	while (stack->data[index] && stack->data[index] != data)
		index++;
	return (index);
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	int	index;
	int	proximity;

	index = get_index(stack_a, pivot);
	proximity = stack_a->size / 2;
	if (stack_a->data[stack_a->top] <= pivot)
		pb(stack_a, stack_b);
	else if (proximity > index)
		rra(stack_a);
	else
		ra(stack_a);
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	proximity;

	index = get_index(stack_b, get_max(stack_b));
	proximity = stack_b->size / 2;
	if (stack_b->data[stack_b->top] == get_max(stack_b))
		pa(stack_a, stack_b);
	else if (proximity > index)
		rrb(stack_b);
	else
		rb(stack_b);
}

void	sort_100(t_stack *stack_a, t_stack *stack_b, int *sorted)
{
	int	pivot;
	int	i;
	int	x;

	i = stack_a->size;
	x = 0;
	pivot = sorted[12];
	while (x < (stack_a->capacity / 12) + 1)
	{	
		while (i <= stack_a->size && i > 0)
		{
			push_to_b(stack_a, stack_b, pivot);
			i--;
		}
		i = stack_a->size;
		pivot = pivot + 12;
		x++;
	}
	while (stack_b->top > -1)
		push_to_a(stack_a, stack_b);
}

void	sort_500(t_stack *stack_a, t_stack *stack_b, int *sorted)
{
	int	x;
	int	i;
	int	pivot;

	x = 0;
	i = stack_a->size;
	pivot = sorted[35];
	while (x < (stack_a->capacity / 35) + 1)
	{	
		while (i <= stack_a->size && i > 0)
		{
			push_to_b(stack_a, stack_b, pivot);
			i--;
		}
		i = stack_a->size;
		pivot = pivot + 35;
		x++;
	}
	while (stack_b->top > -1)
		push_to_a(stack_a, stack_b);
}
