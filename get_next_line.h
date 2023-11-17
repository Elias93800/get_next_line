/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:38 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/17 17:12:33 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER 10

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;

char *get_next_line(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);

#endif