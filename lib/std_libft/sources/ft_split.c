/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:47:48 by valentin          #+#    #+#             */
/*   Updated: 2023/07/11 13:14:07 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_sep(char a, char c)
{
	if (a == c)
		return (1);
	return (0);
}

static int	count_words(char *s, char c)
{
	int	i;
	int	nb_of_words;

	if (!(*s))
		return (0);
	nb_of_words = 0;
	if (!is_sep(s[0], c))
		nb_of_words++;
	i = 1;
	while (s[i])
	{
		if (is_sep(s[i - 1], c) && !is_sep(s[i], c))
			nb_of_words++;
		i++;
	}
	return (nb_of_words);
}

static void	alloc_space_for_words(char **split, char *str, char c)
{
	int	i;
	int	word_position;

	word_position = 0;
	while (*str)
	{		
		while (is_sep(*str, c) && *str)
			str++;
		i = 0;
		while (!is_sep(str[i], c) && str[i])
			i++;
		if (i != 0)
			split[word_position] = malloc((i + 1) * sizeof(char));
		word_position++;
		str = (str + i);
	}
}

static void	put_words(char **split, char *str, char c, int nb_of_words)
{
	int	x;
	int	y;
	int	i;

	if (*str)
	{
		x = 0;
		i = 0;
		while (x < nb_of_words)
		{
			while (str[i] && is_sep(str[i], c))
				i++;
			y = 0;
			while (str[i] && !is_sep(str[i], c))
				split[x][y++] = str[i++];
			split[x][y] = '\0';
			x++;
		}
	}
}

char	**ft_split(char *s, char c)
{
	char	**split;
	int		nb_of_words;

	if (!s)
		return (NULL);
	nb_of_words = count_words(s, c);
	split = malloc((nb_of_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	alloc_space_for_words(split, s, c);
	put_words(split, s, c, nb_of_words);
	split[nb_of_words] = NULL;
	return (split);
}
