/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:53:56 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 12:48:04 by hepiment         ###   ########.fr       */
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
	while (stack->data[index] != data)
		index++;
	return (index);
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	proximity;
	int	key_number;

	
	key_number = get_min(stack_a);
	if (stack_a->capacity == 100)
		key_number = get_min(stack_a);
	else if (stack_a->capacity == 500)
		key_number = get_min(stack_a);
	index = get_index(stack_a, key_number);
	proximity = stack_a->size / 2;
	if (stack_a->data[stack_a->top] == stack_a->data[index])
		pb(stack_a, stack_b);
	else if (proximity > index)
		rra(stack_a);
	else
		ra(stack_a);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	// int	*sorted;

	// sorted = sort_stack(stack_a->size, stack_a->data);
	while (!is_sorted(stack_a))
		push_to_b(stack_a, stack_b);
	while (stack_b->top > -1)
		pa(stack_a, stack_b);
	
}

// void	complex_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	max;
// 	int	min;
//
// 	min = get_min(stack_a);
// 	max = get_max(stack_a);
// 	for (int x = stack_a->top; stack_a->data[x]; x--)
// 		printf("Stack_A: %d		Stack_B: %d\n", stack_a->data[x], stack_b->data[x]);
// 	while (!is_sorted(stack_a))
// 	{
// 		/* Manter o maior e o menor número na stack e ordenando a stack_a ao mesmo tempo. Caso o número do topo for maior do que o da base e menor que o seu anterior ele vai para baixo ordenando a stack_a */
// 		if ((stack_a->data[stack_a->top] < stack_a->data[stack_a->top - 1] && stack_a->data[stack_a->top] > stack_a->data[0]) || stack_a->data[stack_a->top] == min || stack_a->data[stack_a->top] == max)
// 		{
// 	/* (Ex:)    Stack_A: 2              Stack_B: 0
// 				Stack_A: 4              Stack_B: 0
// 				Stack_A: 1              Stack_B: 0
// 				Stack_A: 5              Stack_B: 0
// 				Stack_A: 3              Stack_B: 0
// 				Stack_A: 6              Stack_B: 0
// 				Stack_A: 7              Stack_B: 0
// 				Stack_A: 9              Stack_B: 0
// 				Stack_A: 8              Stack_B: 0
// 				pb
// 				Moveu para a stack_b 2
// 				pb
// 				Moveu para a stack_b 4
// 				Stack_A: 1
// 				Stack_A: 5
// 				Stack_A: 3
// 				Stack_A: 6
// 				Stack_A: 7
// 				Stack_A: 9
// 				Stack_A: 8
// 				Rotacionou para baixo 1
// 				ra
// 				pb
// 				Moveu para a stack_b 5
// 				Stack_A: 3
// 				Stack_A: 6
// 				Stack_A: 7
// 				Stack_A: 9
// 				Stack_A: 8
// 				Stack_A: 1
// 				Rotacionou para baixo 3
// 				ra
// 				Stack_A: 6
// 				Stack_A: 7
// 				Stack_A: 9
// 				Stack_A: 8
// 				Stack_A: 1
// 				Stack_A: 3
// 				Rotacionou para baixo 6
// 				ra
// 				Stack_A: 7
// 				Stack_A: 9
// 				Stack_A: 8
// 				Stack_A: 1
// 				Stack_A: 3
// 				Stack_A: 6
// 				Rotacionou para baixo 7
// 				ra
// 				Stack_A: 9
// 				Stack_A: 8
// 				Stack_A: 1
// 				Stack_A: 3
// 				Stack_A: 6
// 				Stack_A: 7
// 				Rotacionou para baixo 9
// 				ra
// 				pb
// 				Moveu para a stack_b 8
// 				Stack_A: 1              Stack_B: 0
// 				Stack_A: 3              Stack_B: 8
// 				Stack_A: 6              Stack_B: 5
// 				Stack_A: 7              Stack_B: 4
// 				Stack_A: 9              Stack_B: 2 */
// 			for (int x = stack_a->top; stack_a->data[x]; x--)
// 				printf("Stack_A: %d\n", stack_a->data[x]);
// 			printf("Moveu %d\n", stack_a->data[stack_a->top]);
// 			ra(stack_a);
// 		}
// 		else
// 		{
// 			pb(stack_a, stack_b);
// 			printf("Foi pra lá %d\n", stack_b->data[stack_b->top]);
// 		}
// 	}
// 	while (stack_b->top >= 0)
// 		return_to_a(stack_a, stack_b);
// 	// while (!is_sorted(stack_a))
// 	// 	moves_five(stack_a);
// 	for (int x = stack_a->top; stack_a->data[x]; x--)
// 		printf("Stack_A: %d		Stack_B: %d\n", stack_a->data[x], stack_b->data[x]);
// }

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
