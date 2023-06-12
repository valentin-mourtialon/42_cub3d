/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:54:02 by valentin          #+#    #+#             */
/*   Updated: 2023/06/12 17:59:06 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_input_infos(t_input_infos *input_infos)
{
	input_infos->filepath = NULL;
	input_infos->filetab = NULL;
	input_infos->fd = 0;
	input_infos->nb_of_lines = 0;
	input_infos->height = 0;
	input_infos->width = 0;
	input_infos->index_end_of_map = 0;
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	/*init_player(&data->player);
	init_texinfo(&data->texinfo);*/
	data->map = NULL;
	init_input_infos(&data->input_infos);
	/*init_img_clean(&data->minimap);
	data->texture_pixels = NULL;
	data->textures = NULL;*/
}