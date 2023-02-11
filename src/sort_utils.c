/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:30:24 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 22:06:52 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int stk_flag)
{
	int		index;
	t_stack	*inst;

	index = -1;
	inst = get_instance(stk_flag);
	if (getsize_stack_a() == 1)
		return (TRUE);
	while (++index < getsize_stack_a() - 1)
		if (inst->top[index] != inst->top[index + 1] - 1)
			return (FALSE);
	return (TRUE);
}

int	getrange(void)
{
	double	range;

	range = 0.0525 * getsize_stack_a() + 8.75;
	if ((range - (int)range) * 10 >= 5)
		range++;
	return ((int)range);
}

int	position_number(int stk_flag, int nbr)
{
	int		pos;
	t_stack	*stk;

	pos = -1;
	stk = get_instance(stk_flag);
	while (++pos < stk->size)
	{
		if (nbr == stk->top[pos])
			return (pos + 1);
		if (nbr == stk->top[stk->size - pos - 1])
			return (stk->size - pos);
	}
	return (-1);
}

void	to_top_stack(int stk_flag, int position)
{
	t_stack	*inst;

	inst = get_instance(stk_flag);
	while (position >= 2)
	{
		if (position-- > inst->size / 2)
		{
			if (stk_flag == STK_B)
				rrotate_stack_b();
			else
				rrotate_stack_a();
			position = (position + 2) % (inst->size + 1);
		}
		else
		{
			if (stk_flag == STK_B)
				rotate_stack_b();
			else
				rotate_stack_a();
		}
	}
}
