/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlopez <hlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:49:20 by hlopez            #+#    #+#             */
/*   Updated: 2024/01/22 13:04:01 by hlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
//# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t l);
size_t	ft_strlcat(char *dest, const char *src, size_t l);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *str, const char *to_find, size_t n);

int		ft_toupper(int c);
int		ft_tolower(int c);

void	ft_bzero(void *s, size_t n);

void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp(const void *pointer1, const void *pointer2, size_t size);

void	*ft_calloc(size_t elementCount, size_t elementSize);

char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(const char *format, ...);
int		ft_print_format(char type, va_list params);

int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnbr(long n, char c);
int		ft_printpointer(unsigned long long n);
int		ft_printptr(unsigned long long n);

char	*get_next_line(int fd);
void	line_treatment(char **line, char **str, char **dest, int fd);
char	*end_read(char **line, char **str, char **dest, ssize_t r);
char	*check_latest_line(char **line, char **dest, size_t i);

char	*ft_strnjoin_custom(char *s1, char *s2, size_t n);
char	*ft_substr_custom(char *s, unsigned int start);
char	*ft_strndup(char *src, size_t l);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif