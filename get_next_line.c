/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/28 22:00:13 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lstclean(t_list *list)
{
	int		i;
	int		j;
	t_list	*last;
	t_list	*clean;

	clean = (t_list *)malloc(sizeof(t_list));
	if (list == NULL || clean == NULL)
		return (NULL);
	clean->next = NULL;
	last = ft_lstlast(list);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i)
				+ 1));
	if (clean->content == NULL)
		return (free(clean), NULL);
	j = 0;
	while (last->content[i])
		clean->content[j++] = last->content[i++];
	clean->content[j] = '\0';
	return (free(last->content), free(last), clean);
}

int	ft_init(t_list *head, int fd)
{
	t_list	*lst;
	char	*buffer;
	int		bytes_read;

	lst = head;
	while (is_nl(lst->content) == 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), bytes_read);
		buffer[bytes_read] = '\0';
		ft_lstadd_back(head, buffer);
		lst = lst->next;
	}
	return (1);
}

char	*create_line(t_list *head, char *res)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 0;
	current = head;
	while (current)
	{
		i = 0;
		while (current->content[i])
		{
			if (current->content[i] == '\n')
			{
				res[j++] = current->content[i];
				break ;
			}
			res[j++] = current->content[i++];
		}
		current = current->next;
	}
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*h;
	char			*res;
	int				byte_read;
	t_list			*t;

	if (fd == -1)
		return (NULL);
	if (!h)
	{
		h = ft_lstnew(malloc(1));
		if (!h)
			return (NULL);
		h->content[0] = '\0';
	}
	byte_read = ft_init(h, fd);
	if (byte_read == -1)
		return (t = ft_lstclean(h), h = NULL, free(t->content), free(t), NULL);
	res = malloc(sizeof(char) * get_size(h) + 1);
	if (!res)
		return (NULL);
	res = create_line(h, res);
	h = ft_lstclean(h);
	if (!*res)
		return (free(res), NULL);
	return (res);
}

// int	main(void)
// {
// 	int fd = open("moha.txt", O_RDWR);
// 	// close(fd);
// 	// fd = open("moha.txt", O_RDWR);		return (-1);

// 	while (1)
// 	{
// 		char *str = get_next_line(fd);
// 		str = get_next_line(fd);
// 		if (!str)
// 			break ;
// 		// printf("--------\n");
// 		printf("%s", str);
// 		// printf("--------\n");
// 		free(str);
// 	}
// 	// get_next_line(fd);
// 	// printf("res = %s\n", get_next_line(fd));
// 	// get_next_line(fd);
// 	// printf("res = %s\n", get_next_line(fd));
// 	// clos
// }