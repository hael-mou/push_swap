/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:09:51 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 22:15:07 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int number_argument, char **argument)
{
	int		*memory;

	memory = NULL;
	if (number_argument < MIN_ARGUMENT_ALLOW)
		return (EXIT_FAILURE);
	if (get_instance(STK_A) == NULL || get_instance(STK_B) == NULL)
		clean_all(memory, EXIT_FAILURE);
	memory = push_swap_init(argument);
	sort();
	/*ft_print(get_instance(STK_A), "stack_a");*/
	/*ft_print(get_instance(STK_B), "stack_b");*/
	clean_all(memory, EXIT_SUCCESS);
}
