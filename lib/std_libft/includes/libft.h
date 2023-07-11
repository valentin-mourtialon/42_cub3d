/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:13:32 by vmourtia          #+#    #+#             */
/*   Updated: 2023/07/11 14:38:37 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putendl_fd(char *str, int fd);
char	*ft_strchr(const char *s, const char c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(char *str);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);

#endif