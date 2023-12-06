/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:38 by emehdaou          #+#    #+#             */
/*   Updated: 2023/12/06 15:16:35 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
	char			*s;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				ft_lstadd_back(t_list *head, char *s);
t_list				*ft_lstnew(char *s);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
t_list				*ft_lstlast(t_list *lst);
int					get_size(t_list *head);
size_t				ft_strlen(const char *s);

#endif