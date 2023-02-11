/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:05:13 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/11 21:42:51 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*##############################################################
#  	   * Includes :		    								   #
##############################################################*/
# include "libft.h"
# include "stack.h"
# include <limits.h>

/*##############################################################
#  	   * Macro definition :								  	   #
##############################################################*/
# define MIN_ARGUMENT_ALLOW	2
# define STATUS 5
# define ON 0
# define OFF 1

/*##############################################################
#  	   * Functions :		    							   #
##############################################################*/
// push_swap :
int		*push_swap_init(char **argument);
void	clean_all(int	*memory, int exit_status);
int		print_switch(int flag);
void	ft_putstr(char *string);
void	ft_print(t_stack *inst, char *title);

//sort:
void	sort(void);

//sort utils:
int		is_sorted(int stk_flag);
int		position_number(int stk_flag, int nbr);
int		getrange(void);
void	to_top_stack(int stk_flag, int position);

// extract argument :
int		count_number(char **argument);
int		*extract_argument(char **argument, int size);

// stack_a rules:
int		getsize_stack_a(void);
void	push_to_stack_a(void);
void	swap_stack_a(void);
void	rotate_stack_a(void);
void	rrotate_stack_a(void);

// stack_b rules:
int		getsize_stack_b(void);
void	push_to_stack_b(void);
void	swap_stack_b(void);
void	rotate_stack_b(void);
void	rrotate_stack_b(void);

// other rules:
void	sswap(void);
void	rr(void);
void	rrr(void);

#endif
