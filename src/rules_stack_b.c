/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:18:09 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 20:52:29 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getsize_stack_b(void)
{
	return (get_instance(STK_B)->size);
}

void	push_to_stack_b(void)
{	
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = get_instance(STK_A);
	stk_b = get_instance(STK_B);
	if (stk_a == NULL || stk_b == NULL || stk_a->size == 0)
		return ;
	rotate(STK_A);
	stk_a->size--;
	stk_b->size++;
	stk_b->top = stk_a->top + stk_a->size;
	ft_putstr("pb\n");
}

void	swap_stack_b(void)
{
	if (swap(STK_B) == SUCCESS)
		ft_putstr("sb\n");
}

void	rotate_stack_b(void)
{
	if (rotate(STK_B) == SUCCESS)
		ft_putstr("rb\n");
}

void	rrotate_stack_b(void)
{
	if (rrotate(STK_B) == SUCCESS)
		ft_putstr("rrb\n");
}
