/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment <hepiment@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:34:13 by hepiment          #+#    #+#             */
/*   Updated: 2022/10/11 15:47:33 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	only_numbers(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicate(int argc, char **argv)
{
	int	i;
	int	pos;

	i = argc - 1;
	pos = i - 1;
	while (i >= 0)
	{
		while (pos >= 0)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[pos]))
				return (1);
			pos--;
		}
		i--;
		pos = i - 1;
	}
	return (0);
}

int	amount_digits(char *argv)
{
	int		i;

	i = 0;
	if (*argv == '-' || *argv == '+')
		argv++;
	while (*argv)
	{
		i++;
		argv++;
	}
	return (i);
}

void	validate(t_stack *stack_a, int argc, char **argv)
{
	long int	number;
	int			i;

	i = 0;
	while (i < argc)
	{
		if (only_numbers(argc, argv))
			error(stack_a);
		number = ft_atoi(argv[i]);
		if ((number >= MAX_INT) || (number <= MIN_INT) || \
		amount_digits(argv[i]) > 10)
		{	
			error(stack_a);
		}
		i++;
	}
	if (is_sorted(stack_a))
	{
		free_all(stack_a);
		exit (0);
	}
	if (duplicate(argc, argv))
		error(stack_a);
}
