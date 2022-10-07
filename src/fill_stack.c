/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:28:18 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 11:00:37 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
}