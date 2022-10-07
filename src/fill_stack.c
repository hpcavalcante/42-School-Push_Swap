/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:28:18 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 18:02:42 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	normalize_a(t_stack *stack_a)
{
	int	min;
	int top;

	min = get_min(stack_a);
	top = stack_a->top;
	if (min < 0)
		min *= -1;
	while (top >= 0)
	{
		stack_a->data[top] += min + 1;
		top--;		
	}
	// for (int x = stack_a->top; stack_a->data[x]; x--)
	// 	printf("Stack A: %d\n", stack_a->data[x]);	
	// exit(0);
}

void	fill_stack(t_stack *stack_a, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = stack_a->top;
	while (i <= stack_a->top)
	{
		stack_a->data[j] = ft_atoi(argv[i + 1]);
		i++;
		j--;
	}
	normalize_a(stack_a);
}
