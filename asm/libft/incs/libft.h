/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleconte <mleconte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:45:41 by mleconte          #+#    #+#             */
/*   Updated: 2016/07/05 15:36:47 by mleconte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include "gnl.h"

void		ft_arrdel(char ***array);
size_t		ft_arrlen(char **array);
char		**ft_array_dup(char **array);
int			ft_array_indexof(char const **array, char const *str);
size_t		ft_array_pop(char ***argv, size_t start, size_t len);
int			ft_array_push_back(char ***array, char const *value);
int			ft_array_push_front(char ***array, char const *value);
int			ft_array_push_index(char ***array, char const *value,
								size_t const index);

size_t		ft_count_char(char const *str, char c);
size_t		ft_count_word(char const *str);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);

void		ft_memdel(void **ap);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_smalloc(size_t n);

void		ft_putarray_fd(char const **array, int fd);
void		ft_putarray(char const **array);
void		ft_putchar(char c);
void		ft_putnchar(char c, int n);
void		ft_putstr(const char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);

int			ft_str_is(int (*f)(int), char const *str);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strclean(char const *str);
void		ft_strclr(char *s);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dest, char const *src);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
int			ft_strequ(char const *s1, char const *s2);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strncat(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(const char *s, int c);
char		**ft_strsplit(char const *s, char c);
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);

int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

int			get_next_line(int const fd, char **line);

#endif
