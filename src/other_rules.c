/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:24:41 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 20:53:03 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sswap(void)
{
	if ((swap(STK_A) == SUCCESS) | (swap(STK_B) == SUCCESS))
		ft_putstr("ss\n");
}

void	rr(void)
{	
	if ((rotate(STK_A) == SUCCESS) | (rotate(STK_B) == SUCCESS))
		ft_putstr("rr\n");
}

void	rrr(void)
{
	if ((rrotate(STK_A) == SUCCESS) | (rrotate(STK_B) == SUCCESS))
		ft_putstr("rrr\n");
}
