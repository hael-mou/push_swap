/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:06:44 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 20:54:34 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_rule(char *line)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (rotate_stack_a(), 0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		return (rotate_stack_b(), 0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (rr(), 0);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		return (push_to_stack_a(), 0);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		return (push_to_stack_b(), 0);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		return (rrotate_stack_a(), 0);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		return (rrotate_stack_b(), 0);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		return (rrr(), 0);
	else if (ft_strncmp(line, "sa\n", 4) == 0)
		return (swap_stack_a(), 0);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		return (swap_stack_b(), 0);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		return (sswap(), 0);
	free(line);
	return (EXIT_FAILURE);
}

int	checker(void)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (apply_rule(line))
			return (EXIT_FAILURE);
		free(line);
	}
	return (EXIT_SUCCESS);
}

int	main(int number_argument, char **argument)
{
	int		*memory;

	memory = NULL;
	if (number_argument < MIN_ARGUMENT_ALLOW)
		return (EXIT_FAILURE);
	if (get_instance(STK_A) == NULL || get_instance(STK_B) == NULL)
		clean_all(memory, EXIT_FAILURE);
	memory = push_swap_init(argument);
	print_switch(OFF);
	if (checker() == EXIT_FAILURE)
		clean_all(memory, EXIT_FAILURE);
	if (is_sorted(STK_A) && getsize_stack_b() == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_all(memory, EXIT_SUCCESS);
}
