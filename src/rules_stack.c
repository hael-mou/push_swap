/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:18:09 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 11:08:20 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(int stk_flag)
{
	int		tmp;
	t_stack	*inst;

	inst = get_instance(stk_flag);
	if (inst == NULL || inst->top == NULL || inst->size < 2)
		return (EXIT_FAILURE);
	tmp = *inst->top;
	*inst->top = *(inst->top + 1);
	*(inst->top + 1) = tmp;
	return (EXIT_SUCCESS);
}

int	rotate(int stk_flag)
{
	int		tmp;
	int		index;
	t_stack	*inst;

	index = -1;
	inst = get_instance(stk_flag);
	if (inst == NULL || inst->top == NULL || inst->size < 2)
		return (EXIT_FAILURE);
	tmp = *inst->top;
	while (++index < inst->size - 1)
		*(inst->top + index) = *(inst->top + index + 1);
	*(inst->top + index) = tmp;
	return (EXIT_SUCCESS);
}

int	rrotate(int stk_flag)
{
	int		tmp;
	int		index;
	t_stack	*inst;

	inst = get_instance(stk_flag);
	if (inst == NULL || inst->top == NULL || inst->size < 2)
		return (EXIT_FAILURE);
	index = inst->size;
	tmp = *(inst->top + index - 1);
	while (--index > 0)
		*(inst->top + index) = *(inst->top + index - 1);
	*(inst->top) = tmp;
	return (EXIT_SUCCESS);
}

t_stack	*get_instance(int stk_flag)
{
	static t_stack	*stks[NBR_STK];

	if (stks[stk_flag] == NULL)
		stks[stk_flag] = ft_calloc(1, sizeof(t_stack));
	return (stks[stk_flag]);
}
