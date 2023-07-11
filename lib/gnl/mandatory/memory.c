/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:36:48 by valentin          #+#    #+#             */
/*   Updated: 2023/07/11 13:10:03 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

t_list	*get_last_memory_element(t_list *memory)
{
	t_list	*last;

	if (memory == NULL)
		return (NULL);
	last = memory;
	while (last && last->next)
		last = last->next;
	return (last);
}

t_list	*memory_new_element(char *buffer, size_t nbytes)
{
	t_list	*new_element;
	size_t	i;

	new_element = malloc(sizeof(*new_element));
	if (new_element == NULL || buffer == NULL)
		return (NULL);
	new_element->next = NULL;
	new_element->str = malloc(sizeof(char) * (nbytes + 1));
	if (new_element->str == NULL)
		return (free(new_element), NULL);
	i = 0;
	while (buffer[i] && i < nbytes)
	{
		new_element->str[i] = buffer[i];
		i++;
	}
	new_element->str[i] = '\0';
	return (new_element);
}

void	add_back_to_memory(t_list **memory, t_gnl *gnl)
{
	t_list	*new_element;
	t_list	*last;

	new_element = memory_new_element(gnl->buffer, gnl->nbytes);
	if (new_element == NULL)
		return ;
	last = get_last_memory_element(*memory);
	if (last == NULL)
	{
		*memory = new_element;
		return ;
	}
	last->next = new_element;
}
