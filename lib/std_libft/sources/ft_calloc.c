/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:25:10 by valentin          #+#    #+#             */
/*   Updated: 2023/06/13 15:29:48 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*output;

	if (size != 0 && nmemb > INT_MAX / size)
		return (NULL);
	output = malloc(nmemb * size);
	if (!output)
		return (NULL);
	ft_bzero(output, nmemb);
	return (output);
}