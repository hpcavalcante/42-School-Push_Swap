/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:24:41 by hepiment          #+#    #+#             */
/*   Updated: 2022/09/30 22:11:09 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_all(t_stack *stack)
{
	free(stack->data);
	stack->data = NULL;
	free(stack);
}

void	error(t_stack *stack)
{
	write(2, "Error\n", 6);
	free_all(stack);
	exit (0);
}
