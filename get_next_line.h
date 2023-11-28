/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:38 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/28 20:31:24 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				ft_lstadd_back(t_list *head, char *content);
t_list				*ft_lstnew(char *content);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstlast(t_list *lst);
int					get_size(t_list *head);
size_t				ft_strlen(const char *str);

#endif