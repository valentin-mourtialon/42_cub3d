/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:11:53 by valentin          #+#    #+#             */
/*   Updated: 2023/06/29 14:06:06 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = calloc(1, sizeof * buffer * data->textures_infos.size
			* data->textures_infos.size);
	if (!buffer)
		exit_program(data, 1);
	y = 0;
	while (y < data->textures_infos.size)
	{
		x = 0;
		while (x < data->textures_infos.size)
		{
			buffer[y * data->textures_infos.size + x]
				= tmp.addr[y * data->textures_infos.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = calloc(5, sizeof * data->textures);
	if (!data->textures)
		exit_program(data, 1);
	data->textures[NORTH] = xpm_to_img(data, data->textures_infos.NO);
	data->textures[SOUTH] = xpm_to_img(data, data->textures_infos.SO);
	data->textures[EAST] = xpm_to_img(data, data->textures_infos.EA);
	data->textures[WEST] = xpm_to_img(data, data->textures_infos.WE);
}
