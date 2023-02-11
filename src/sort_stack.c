/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:22:36 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 22:14:45 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_with_range(int range)
{
	static int	index;
	int			top;

	top = *get_instance(STK_A)->top;
	if (top <= index + range)
	{	
		push_to_stack_b();
		if (top > index++)
			return ;
		top = *get_instance(STK_A)->top;
		if (top > index + range)
			rr();
		else
			rotate_stack_b();
	}
	else
		rotate_stack_a();
}

void	sort_size_3(int big)
{
	int	pos;

	pos = position_number(STK_A, big);
	if (pos == 1)
		rotate_stack_a();
	else if (pos == 2)
		rrotate_stack_a();
	if (!is_sorted(STK_A))
		swap_stack_a();
}

void	sort_small_stack(void)
{
	int	s_pos;
	int	index;
	int	big;

	index = 1;
	big = getsize_stack_a();
	while (getsize_stack_a() > 3)
	{
		s_pos = position_number(STK_A, index++);
		to_top_stack(STK_A, s_pos);
		push_to_stack_b();
	}
	if (!is_sorted(STK_A))
		sort_size_3(big);
	while (getsize_stack_b() > 0)
		push_to_stack_a();
}

void	sort(void)
{
	int	range;

	if (is_sorted(STK_A))
		return ;
	if (getsize_stack_a() <= 5)
	{
		sort_small_stack();
		return ;
	}
	range = getrange();
	while (getsize_stack_a())
		push_with_range(range);
	while (getsize_stack_b())
	{
		to_top_stack(STK_B,
			position_number(STK_B, getsize_stack_b()));
		push_to_stack_a();
	}
}
