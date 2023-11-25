/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:33 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/24 19:32:40 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s2;

	s2 = (char *)s;
	while (n > 0)
	{
		*s2 = '\0';
		s2++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (size != 0 && __SIZE_MAX__ / size < nmemb)
		return (NULL);
	s = malloc(nmemb * size);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}

void	ft_lstadd_back(t_list *head, char* content)
{
	t_list	*current;
	t_list	*new;

	// new = malloc(sizeof(t_list));
	// new->content = content;
	// if (!new)
	// 	return ;
	new = ft_lstnew(content);
	if (!new)
		return ;
	current = head;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

