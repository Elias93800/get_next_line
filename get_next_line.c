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

int	is_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstclean(t_list *lst, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (lst != NULL && i <= size)
	{
		if (lst->content[i] == '\n')
			lst->content = &lst->content[i];
		if (lst->content[i] == '\0')
		{
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
	}
	return (lst);
}

void	ft_init(t_list *lst, int fd)
{
	char	*buffer;
	int		bytes_read;

	while ( lst != NULL && is_nl(lst->content) == 0)
	{
		buffer = ft_calloc(sizeof(char *), SIZE_BUFFER + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, SIZE_BUFFER);
		if (bytes_read == 0)
			break;
		printf("buffer = %s ", buffer);
		printf("byte read = %d\n", bytes_read);
		ft_lstadd_back(&lst, buffer);
		free(buffer);
		lst = lst->next;
	}
}

int	create_line(t_list *lst, char **res)
{
	t_list	*current;
	int		i;

	current = lst;
	i = 0;
	while (current != NULL && current->content[i] != '\n')
	{
		i++;
		if (current->content[i] == '\0')
			current = current->next;
	}
	printf("i = %d\n", i);
	*res = ft_calloc(sizeof(char *), i + 1);
    if (!res)
	{
    	return (0);
	}
	i = 0;
	current = lst;
	while (current != NULL && current->content[i] != '\n')
	{
		*res[i] = current->content[i];
		i++;
		if (current->content[i] == '\0')
			current = current->next;
	}
	*res[i] = '\n';
	return (i);
}

void print_list(t_list *first_node)
{
     t_list  *current;

     current = first_node;
     while (current != NULL)
     {
             printf("%s\n", current->content);
             current = current->next;
     }
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*res;
	int				size;

    lst = ft_lstnew(NULL);
	ft_init(lst, fd);
	print_list(lst);
	size = create_line(lst, &res);
	if (size == 0)
		return (0);
	lst = ft_lstclean(lst, size);
	printf("res = %s\n", res);
	return (res);
}

int main()
{
	int fd = open("gnlTester/files/41_with_nl", O_RDWR);
	get_next_line(fd);
    // printf("%s\n", get_next_line(fd));    
}