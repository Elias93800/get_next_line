/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:33 by emehdaou          #+#    #+#             */
/*   Updated: 2023/12/06 12:18:07 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_list *head, char *str)
{
	t_list	*current;
	t_list	*new;

	new = ft_lstnew(str);
	if (!new)
		return ;
	if (!head)
		head = new;
	else
	{
		current = head;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_list	*ft_lstnew(char *str)
{
	t_list	*new;

	if (!str)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->str = str;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (lst->next)
	{
		if (lst && lst->str)
			free(lst->str);
		last = lst->next;
		free(lst);
		lst = last;
	}
	return (last);
}

int	get_size(t_list *head)
{
	t_list	*lst;
	int		i;
	int		size;

	size = 0;
	lst = head;
	i = 0;
	while (lst != NULL && lst->str[i] != '\n')
	{
		if (lst->str[i] == '\0')
		{
			lst = lst->next;
			i = 0;
		}
		else
		{
			i++;
			size++;
		}
	}
	return (size + 1);
}
