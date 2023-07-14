/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-maar <sel-maar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:10:13 by vmourtia          #+#    #+#             */
/*   Updated: 2023/07/14 14:48:38 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_ptr(void *ptr)
{
	if (ptr == NULL)
		return ;
	free(ptr);
	ptr = NULL;
}

void	free_tab(void **tab)
{
	size_t	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

static void	free_textures_infos(t_textures_infos *textures_infos)
{
	if (textures_infos->no)
		free(textures_infos->no);
	if (textures_infos->so)
		free(textures_infos->so);
	if (textures_infos->we)
		free(textures_infos->we);
	if (textures_infos->ea)
		free(textures_infos->ea);
	if (textures_infos->f)
		free(textures_infos->f);
	if (textures_infos->c)
		free(textures_infos->c);
}

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->textures)
		free_tab((void **)data->textures);
	if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);
	free_textures_infos(&data->textures_infos);
	if (data->input_infos.fd > 0)
		close(data->input_infos.fd);
	if (data->input_infos.filetab)
		free_tab((void **)data->input_infos.filetab);
	if (data->map)
		free_tab((void **)data->map);
}

void	free_gnl(char *line, t_data *data)
{
	while (line)
	{
		free(line);
		line = get_next_line(data->input_infos.fd);
	}
}
