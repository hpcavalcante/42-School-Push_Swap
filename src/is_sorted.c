/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:56:49 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 12:48:23 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->top;
	if (stack_a->top == -1)
		return (1);
	while (i > 0)
	{
		if (stack_a->data[i] > stack_a->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}
