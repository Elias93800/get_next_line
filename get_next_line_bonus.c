/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/12/06 15:17:28 by emehdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*clean(t_list *list)
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
	while (last->s[i] && last->s[i] != '\n')
		i++;
	if (last->s && last->s[i] == '\n')
		i++;
	clean->s = malloc(sizeof(char) * ((ft_strlen(last->s) - i) + 1));
	if (clean->s == NULL)
		return (free(clean), NULL);
	j = 0;
	while (last->s[i])
		clean->s[j++] = last->s[i++];
	clean->s[j] = '\0';
	return (free(last->s), free(last), clean);
}

int	ft_init(t_list *head, int fd)
{
	t_list	*lst;
	char	*buffer;
	int		bytes_read;

	lst = head;
	while (is_nl(lst->s) == 0)
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
		while (current->s[i])
		{
			if (current->s[i] == '\n')
			{
				res[j++] = current->s[i];
				break ;
			}
			res[j++] = current->s[i++];
		}
		current = current->next;
	}
	res[j] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*h[1024];
	char			*res;
	int				byte_read;
	t_list			*t;

	if (fd == -1 || fd > 1023)
		return (NULL);
	if (!h[fd])
	{
		h[fd] = ft_lstnew(malloc(1));
		if (!h[fd])
			return (NULL);
		h[fd]->s[0] = '\0';
	}
	byte_read = ft_init(h[fd], fd);
	if (byte_read == -1)
		return (t = clean(h[fd]), h[fd] = NULL, free(t->s), free(t), NULL);
	res = malloc(sizeof(char) * get_size(h[fd]) + 1);
	if (!res)
		return (NULL);
	res = create_line(h[fd], res);
	h[fd] = clean(h[fd]);
	if (!*res)
		return (free(res), t = h[fd], h[fd] = NULL, free(t->s), free(t), NULL);
	return (res);
}

// int	main(void)
// {
// 	int fd = open("get_next_line.h", O_RDWR);
// 	// close(fd);
// 	// fd = open("moha.txt", O_RDWR);		return (-1);

// 	while (1)
// 	{
// 		char *s = get_next_line(fd);
// 		if (!s)
// 			break ;
// 		// printf("--------\n");
// 		printf("%s", s);
// 		// printf("--------\n");
// 		free(s);
// 	}
// 	// get_next_line(fd);
// 	// printf("res = %s\n", get_next_line(fd));
// 	// get_next_line(fd);
// 	// printf("res = %s\n", get_next_line(fd));
// 	// clos
// }