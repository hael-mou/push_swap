/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:37:42 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/06 15:37:43 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int		sign;
	int		nbr;

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
	while (ft_isdigit(*string))
		nbr = nbr * 10 + (*string++) - '0';
	return (nbr * sign);
}
