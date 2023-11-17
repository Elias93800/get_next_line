/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/17 17:20:08 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static t_list *lst;
    int i;
    
    i = 0;
    lst = malloc(sizeof(t_list));
    read(fd, lst->content, BUFFER);
    while(i <= BUFFER && lst->content[i] != '\n')
        i++;
    if (lst->content != '\n')
    {
        ft_lstadd_back(&lst, ft_lstnew(NULL))
    }
}