/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 02:08:17 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/30 15:16:12 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_max(t_stack *stack)
{
	int i;
	int	max;

	i = stack->top;
	max = stack->data[0];
	while(i)
	{
		if(max < stack->data[i])
			max = stack->data[i];
		i--;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int i;
	int	min;

	i = stack->top;
	min = stack->data[0];
	while(i)
	{
		if(min > stack->data[i])
			min = stack->data[i];
		i--;
	}
	return (min);
}

