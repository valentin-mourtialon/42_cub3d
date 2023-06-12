/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:24:30 by valentin          #+#    #+#             */
/*   Updated: 2023/06/12 16:45:34 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

/* 
	nbytes is the number of bytes read by
	the read() function.

	The following statement ensure that if
	we don't read the entire file the static
	memory is still freed (catch with a 
	negative file descriptor) !
	if (memory != NULL)
		free_memory(memory);
*/
static int	init_gnl(t_gnl *gnl, int fd, t_list **memory)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &fd, 0) < 0)
	{
		if (memory != NULL)
			free_memory(memory);
		return (0);
	}
	gnl->fd = fd;
	gnl->nbytes = 1;
	gnl->line = NULL;
	gnl->buffer = NULL;
	return (1);
}

/*
	No need to protect the get_last_memory_element
	return as the only way for this function
	to return a NULL is to send it a NULL but
	we already check that memory isn't NULL before
	sending it. 
*/
static int	find_newline(t_list *memory)
{
	t_list	*memptr;
	int		i;

	if (memory == NULL)
		return (0);
	memptr = get_last_memory_element(memory);
	i = 0;
	while (memptr->str && memptr->str[i])
	{
		if (memptr->str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
	While there'se no newline in memory 
	AND read() function reads 1 or more bytes.

	The first if-condition INSIDE the while-loop:
		1. memory == NULL && gnl.nbytes == 0
		2. gnl.nbytes == -1

		1. is the case where we first pass 
		on our file (as the memory is NULL) 
		and we didn't read anything from 
		the file (nbytes == 0).
*/
static void	read_and_save(t_list **memory, t_gnl *gnl)
{
	while (find_newline(*memory) == 0 && gnl->nbytes != 0)
	{
		gnl->buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (gnl->buffer == NULL)
			return;
		gnl->nbytes = read(gnl->fd, gnl->buffer, BUFFER_SIZE);
		if ((*memory == NULL && gnl->nbytes == 0) || (int)gnl->nbytes == -1)
		{
			free(gnl->buffer);
			return;
		}
		gnl->buffer[gnl->nbytes] = '\0';
		add_back_to_memory(memory, gnl);
		free(gnl->buffer);
		gnl->buffer = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*memory = NULL;
	t_gnl			gnl;

	if (init_gnl(&gnl, fd, &memory) == 0)
		return (NULL);
	read_and_save(&memory, &gnl);
	if (memory == NULL)
		return (NULL);
	extract_line(memory, &gnl);
	clear_memory(&memory);
	if (gnl.line[0] == '\0')
	{
		free_memory(&memory);
		memory = NULL;
		free(gnl.line);
		return (NULL);
	}
	return (gnl.line);
}
