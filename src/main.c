/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:47:00 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/07 18:50:54 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = init_stack_a(stack_a, argc, argv);
		stack_b = init_stack_b(stack_b, argc);
		push_swap(stack_a, stack_b, argc);
		free_all(stack_a);
		free_all(stack_b);
	}
	return (0);
}
