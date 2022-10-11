/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:53:56 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:52:15 by hepiment         ###   ########.fr       */
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
