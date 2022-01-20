/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnazioze <vnazioze@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:35:24 by user42            #+#    #+#             */
/*   Updated: 2022/01/16 04:14:55 by vnazioze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# define BUFFER_SIZE 1
# define OPEN_MAX 256

char	*get_next_line(int fd);

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t lengh);
void	*ft_memcpy(void *destiny, const void *source, size_t lengh);
void	*ft_memmove(void *destiny, const void *source, size_t lengh);
int		ft_toupper(int character);
int		ft_tolower(int character);
void	*ft_memchr(const void *string, int character, size_t lengh);
int		ft_memcmp(const void *string1, const void *string2, size_t lengh);
char	*ft_strchr(const char *string, int character);
char	*ft_strrchr(const char *string, int character);
int		ft_strncmp(const char *string1, const char *string2, size_t lengh);
char	*ft_strnstr(const char *string, const char *sub_string, size_t lengh);
size_t	ft_strlcpy(char *destiny, const char *source, size_t destiny_size);
size_t	ft_strlcat(char *destiny, const char *source, size_t destiny_size);
int		ft_atoi(const char *string);
void	*ft_calloc(size_t number_elements, size_t size);
char	*ft_strdup(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif
