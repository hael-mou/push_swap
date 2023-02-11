/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:25:28 by hael-mou          #+#    #+#             */
/*   Updated: 2023/02/09 19:57:03 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line.h"

/*###############################################################
#  	   * struct & enum :										#
###############################################################*/
enum e_boolean
{
	FALSE,
	TRUE
};

/*###############################################################
#  	   * Functions :											#
###############################################################*/
// Checks Functions: 
int		ft_isalpha(int character);
int		ft_isupper(int character);
int		ft_islower(int character);
int		ft_isdigit(int character);
int		ft_isalnum(int character);
int		ft_isascii(int character);
int		ft_isprint(int character);
int		ft_isspace(int character);
int		ft_isxdigit(int character);

// Convert Functions:
int		ft_atoi(const char *string);
char	*ft_itoa(int number);
int		ft_tolower(int character);
int		ft_toupper(int character);

// Print Functions:
void	ft_putchar_fd(char character, int fd);
void	ft_putstr_fd(char *string, int fd);
void	ft_putendl_fd(char *string, int fd);
void	ft_putnbr_fd(int number, int fd);

// Memory Function:
void	*ft_memset(void *memory, int constant, size_t len);
void	ft_bzero(void *memory, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memchr(const void *memory, int c, size_t len);
int		ft_memcmp(const void *mem1, const void *mem2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);

// String Function:
char	**ft_split(char const *string, char delim);
int		ft_strcout(char const *string, char delim);
size_t	ft_strlen(const char *string);
char	*ft_strdup(const char *string);
char	*ft_strchr(const char *string, int character);
void	ft_striteri(char *string, void (*fun)(unsigned int, char *));
char	*ft_strmapi(char const *string, char (*fun)(unsigned int, char));
char	*ft_strjoin(char const *string1, char const *string2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *string1, const char *string2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *string, int character);
char	*ft_strtok(char const *string, char delim);
char	*ft_strtrim(char const *string, char const *set);
char	*ft_substr(char const *string, unsigned int start, size_t len);

// number:
int		ft_nbrlen(int number);
int		ft_nbrnchr(int *array, int number, int len);

#endif
