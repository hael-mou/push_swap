/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:37:29 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 20:56:26 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print(t_stack *inst, char *title)
{
	int	i;

	i = -1;
	printf("\n------------%s----------------\n", title);
	while (++i < inst->size)
		printf("%d\n", inst->top[i]);
}

int	*push_swap_init(char **argument)
{
	int		*memory;

	get_instance(STK_A)->size = count_number(argument + 1);
	memory = extract_argument(argument, getsize_stack_a());
	get_instance(STK_A)->top = memory;
	return (memory);
}

int	print_switch(int flag)
{
	static int	p_switch;

	if (flag == STATUS)
		return (p_switch);
	p_switch = (flag == OFF);
	return (p_switch);
}

void	ft_putstr(char *string)
{
	int	p_switch;

	p_switch = print_switch(STATUS);
	if (p_switch == ON)
		ft_putstr_fd(string, 1);
}

void	clean_all(int *memory, int exit_status)
{
	free(memory);
	free(get_instance(STK_A));
	free(get_instance(STK_B));
	if (exit_status == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	exit(exit_status);
}
