/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:53:56 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 19:18:14 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simple_sort(t_stack *stack_a)
{
	int	top;
	int	middle;
	int	botton;

	top = stack_a->data[stack_a->top];
	middle = stack_a->data[stack_a->top - 1];
	botton = stack_a->data[0];
	if (top > middle && middle < botton && botton > top)
		sa(stack_a);
	else if (top < middle && middle > botton && botton < top)
		rra(stack_a);
	else if (top > middle && middle < botton && botton < top)
		ra(stack_a);
	else if (top > middle && middle > botton && botton < top)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top < middle && middle > botton && botton > top)
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	mid_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min(stack_a);
	while (stack_a->size > 3)
	{
		if (stack_a->data[stack_a->top] == min)
		{
			pb(stack_a, stack_b);
			min = get_min(stack_a);
		}
		else
			ra(stack_a);
	}
	simple_sort(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

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
	pivot = sorted[20];
	while (x < (stack_a->capacity / 20) + 1)
	{	
		while (i <= stack_a->size && i > 0)
		{
			push_to_b(stack_a, stack_b, pivot);
			i--;
		}
		i = stack_a->size;
		pivot = pivot + 20;
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

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*sorted;

	sorted = sort_stack(stack_a);
	if (stack_a->capacity < 500)
		sort_100(stack_a, stack_b, sorted);
	else if (stack_a->capacity >= 500)
		sort_500(stack_a, stack_b, sorted);
	free(sorted);
}


void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc)
{
	if (argc == 3)
		sa(stack_a);
	else if (argc < 5)
		simple_sort(stack_a);
	else if (argc <= 6 && argc > 3)
		mid_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}
