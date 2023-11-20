/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/20 21:41:49 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstclean(t_list *lst, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
    tmp = malloc(sizeof(t_list*));
	while (i <= size)
	{
		if (lst->content[i] == '\n')
			lst->content = &lst->content[i];
		if (lst->content[i] == '\0')
		{
			tmp = lst->next;
			free(lst);
		}
	}
	return (lst);
}

void	ft_init(t_list *lst, int fd)
{
	char	*buffer;
	int		bytes_read;

	while (!is_nl(lst->content) && lst != NULL && bytes_read != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[++bytes_read] = '\0';
		ft_lstadd_back(&lst, buffer);
		free(buffer);
		lst = lst->next;
	}
}

int	create_line(t_list *lst, char *res)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	while (current->content[i] != '\n')
	{
		i++;
		if (current->content[i] == '\0')
			current = current->next;
	}
	res = ft_calloc(sizeof(char *), i + 1);
    if (!res)
        return (0);
	i = 0;
	while (current->content[i] != '\n')
	{
		res[i] = current->content[i];
		i++;
		if (current->content[i] == '\0')
			current = current->next;
	}
	res[++i] = '\n';
	return (i);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*res;
	int				size;

    ft_lstnew(lst);
	ft_init(lst, fd);
	size = create_line(lst, res);
	if (size == 0)
		return (NULL);
	lst = ft_lstclean(lst, size);
	return (res);
}

// int main()
// {
//     printf(get_next_line)    
// }