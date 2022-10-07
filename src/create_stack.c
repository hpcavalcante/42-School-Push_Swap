/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:45:44 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/05 05:19:53 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		*sort_stack(int size, int *stack)
{
	int		temp;
	int		i;
	int		j;
	
	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (stack[i] > stack[j])
			{
				temp = stack[i];
				stack[i] = stack[j];
				stack[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (stack);
}
