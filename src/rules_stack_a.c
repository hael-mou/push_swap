/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:18:09 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 20:51:31 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getsize_stack_a(void)
{
	return (get_instance(STK_A)->size);
}

void	push_to_stack_a(void)
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = get_instance(STK_A);
	stk_b = get_instance(STK_B);
	if (stk_a == NULL || stk_b == NULL || stk_b->size == 0)
		return ;
	stk_a->size++;
	stk_b->size--;
	rrotate(STK_A);
	stk_b->top = stk_a->top + stk_a->size;
	ft_putstr("pa\n");
}

void	swap_stack_a(void)
{
	if (swap(STK_A) == SUCCESS)
		ft_putstr("sa\n");
}

void	rotate_stack_a(void)
{
	if (rotate(STK_A) == SUCCESS)
		ft_putstr("ra\n");
}

void	rrotate_stack_a(void)
{
	if (rrotate(STK_A) == SUCCESS)
		ft_putstr("rra\n");
}
