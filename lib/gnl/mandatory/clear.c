/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:32:39 by valentin          #+#    #+#             */
/*   Updated: 2023/02/03 15:55:27 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

void	free_memory(t_list **memory)
{
	t_list	*nexttmp;
	t_list	*memptr;

	memptr = *memory;
	while (memptr)
	{
		free(memptr->str);
		nexttmp = memptr->next;
		free(memptr);
		memptr = nexttmp;
	}
}

/*
	Example:
*/
void	clear_memory(t_list **memory)
{
	int		i;
	int		j;
	t_list	*cleared_node;
	t_list	*last;

	cleared_node = malloc(sizeof(*cleared_node));
	if (memory == NULL || cleared_node == NULL)
		return;
	cleared_node->next = NULL;
	last = get_last_memory_element(*memory);
	i = 0;
	while (last->str[i] && last->str[i] != '\n')
		i++;
	if (last->str && last->str[i] == '\n')
		i++;
	cleared_node->str = malloc(sizeof(char) * (ft_strlen(last->str) - i + 1));
	if (cleared_node == NULL)
		return;
	j = 0;
	while (last->str[i])
		cleared_node->str[j++] = last->str[i++];
	cleared_node->str[j] = '\0';
	free_memory(memory);
	*memory = cleared_node;
}