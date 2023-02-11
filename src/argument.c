/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:09:00 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 20:07:48 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number(char **av)
{
	int	count;

	count = 0;
	while (av && *av)
		count += ft_strcout(*av++, 32);
	return (count);
}

long	ft_atol(const char *string)
{
	int		sign;
	long	nbr;

	nbr = 0;
	sign = 1;
	while (ft_isspace(*string))
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	if (*string == '\0')
		return ((long)INT_MAX + 5);
	while (ft_isdigit(*string))
		nbr = nbr * 10 + (*string++) - '0';
	nbr = nbr * !(*string) + ((long)INT_MAX + 5) * !!(*string);
	return (nbr * sign);
}

void	count_pos(int *list, int *pos_list, int size)
{
	int	select;
	int	index;

	pos_list[size - 1]++;
	if (size < 2)
		return ;
	count_pos(list, pos_list, size - 1);
	select = list[--size];
	index = size;
	while (--index >= 0)
	{
		pos_list[index] += (list[index] > select);
		pos_list[size] += !(list[index] > select);
	}
}

void	strtoi(int	*memory, char *string, int *index)
{
	char	**tmp;
	long	number;
	int		i;

	i = -1;
	tmp = ft_split(string, 32);
	if (!tmp || !*tmp)
		clean_all(memory, EXIT_FAILURE);
	while (tmp[++i])
	{
		number = ft_atol(tmp[i]);
		if (number > INT_MAX || number < INT_MIN
			|| ft_nbrnchr(memory, number, *index))
			clean_all(memory, EXIT_FAILURE);
		memory[(*index)++] = (int)number;
		free(tmp[i]);
	}
	free(tmp);
}

int	*extract_argument(char **argument, int size)
{
	int	*list;
	int	*pos_list;
	int	index;

	index = 0;
	list = ft_calloc(size, sizeof(int));
	pos_list = ft_calloc(size, sizeof(int));
	if (list == NULL || pos_list == NULL)
	{
		free(pos_list);
		clean_all(list, EXIT_FAILURE);
	}
	while (argument && *(++argument))
		strtoi(list, *argument, &index);
	count_pos(list, pos_list, size);
	free(list);
	return (pos_list);
}
