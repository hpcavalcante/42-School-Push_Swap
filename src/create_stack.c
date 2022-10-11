/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:45:44 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:44:01 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*create_stack(t_stack *stack)
{
	int	i;
	int	*sorted;

	i = 0;
	sorted = ft_calloc(sizeof(int), stack->capacity);
	while (i < stack->size)
	{
		sorted[i] = stack->data[i];
		i++;
	}
	return (sorted);
}

int	*sort_stack(t_stack *stack)
{
	int		temp;
	int		j;
	int		i;
	int		*sorted;

	i = 0;
	sorted = create_stack(stack);
	while (i < stack->size)
	{
		j = i;
		while (j < stack->size)
		{
			if (sorted[i] > sorted[j])
			{
				temp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted);
}
