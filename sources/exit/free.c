/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:10:13 by vmourtia          #+#    #+#             */
/*   Updated: 2023/06/13 15:45:31 by valentin         ###   ########.fr       */
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
	if (textures_infos->NO)
		free(textures_infos->NO);
	if (textures_infos->SO)
		free(textures_infos->SO);
	if (textures_infos->WE)
		free(textures_infos->WE);
	if (textures_infos->EA)
		free(textures_infos->EA);
	if (textures_infos->F)
		free(textures_infos->F);
	if (textures_infos->C)
		free(textures_infos->C);
}

void	free_data(t_data *data)
{
	/*if (data->textures)
		free_tab((void **)data->textures);*/
	/*if (data->texture_pixels)
		free_tab((void **)data->texture_pixels);*/
	free_textures_infos(&data->textures_infos);
	if (data->input_infos.fd > 0)
		close(data->input_infos.fd);
	if (data->input_infos.filetab)
		free_tab((void **)data->input_infos.filetab);
	/*if (data->map)
		free_tab((void **)data->map);*/
}