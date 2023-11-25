/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emehdaou <emehdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:58:44 by emehdaou          #+#    #+#             */
/*   Updated: 2023/11/25 01:04:23 by emehdaou         ###   ########.fr       */
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

t_list	*ft_lstclean(t_list *head)
{
	t_list	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (!is_nl(head->content))
	{
		// printf("head->content = %s\n", head->content);
		if (head->next)
			tmp = head->next;
		free(head);
		head = tmp;
	}
	// "avionsadsadasd\nassdasd"
	while (head->content && is_nl(head->content))
	{
		// printf("len = %li\n", strlen(head->content));
		// printf("[%c]", head->content[i]);
		if (head->content[i] == '\n' && head->content[i + 1])
		{
			char *str = strdup(&head->content[i + 1]);
			// printf("str = {%s}", str);
			free(head->content);
			head->content = strdup(str);
			i = -1;
		}
		else if (head->content[i + 1] == '\0')
			return (free(head->content), free(head), NULL);

		i++;
	}
	// printf("\n");
	// printf("head->content = {%s}\n", head->content);
	return (head);
}

int	ft_init(t_list *head, int fd, int *size)
{
	t_list	*lst;
	char	*buffer;
	int		bytes_read;
	int		i;

	lst = head;
	bytes_read = 0;
	while (is_nl(lst->content) == 0)
	{
		buffer = ft_calloc(sizeof(char), SIZE_BUFFER + 1);
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, SIZE_BUFFER);
		if (bytes_read <= 0)
			return (bytes_read);
		ft_lstadd_back(head, buffer);
		lst = lst->next;
	}
	lst = head;
	i = 0;
	while (lst != NULL && lst->content[i] != '\n')
	{
		if (lst->content[i] == '\0')
		{
			lst = lst->next;
			i = 0;
		}
		else
		{
			i++;
			(*size)++;
		}
	}
	// printf("backslash n at : [%i]\n", *size);
	return ((*size) += 1, bytes_read);
}

char	*create_line(t_list *head, char *res)
{
	t_list	*current;
	int		i;
	int		j;

	i = 0;
	j = 0;
	current = head;
	while (current != NULL)
	{
		if (!current->content)
			break ;
		if (current->content[i] == '\0')
		{
			current = current->next;
			i = 0;
		}
		// if (!current->content)
		// 	break ;
		// printf("j = %i| curr [%c]\n", j, current->content[i]);
		res[j] = current->content[i];
		if (res[j] == '\n')
		{
			// printf("res = {%s}", res);
			return (res);
		}
		
		// printf("[%c|%c]\n", res[j], current->content[i]);
		i++;
		j++;
	}
	return (res);
}

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf(">>>>[%s]{%zu}|", current->content, strlen(current->content));
		current = current->next;
	}
	printf("\n");
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*res;
	int				size;
	int byte_read;
	
	size = 0;
	if (!head)
		head = ft_lstnew("");
	byte_read = ft_init(head, fd, &size);
	if (byte_read == -1)
		return(ft_lstclean(head), NULL);
	else if (byte_read == 0)
		return(NULL);
	res = ft_calloc(sizeof(char), size + 1);
	// print_list(head);
	// printf("SIZE DE RES = %i\n", size);
	res = create_line(head, res);
	head = ft_lstclean(head);
	// printf("res = %s\n", res);
	// print_list(head);
	// print_list(head);
	return (res);
}


// qweuquwe

int	main(void)
{
	int fd = open("./get_next_line.h", O_RDWR);
	while (1)
	{
		char *str = get_next_line(fd);
		if (!str)
			break ;
		// printf("--------\n");
		printf("%s", str);
		// printf("--------\n");
		free(str);
	}
	// get_next_line(fd);
	// printf("res = %s\n", get_next_line(fd));
	// get_next_line(fd);
	// printf("res = %s\n", get_next_line(fd));
	// clos
}