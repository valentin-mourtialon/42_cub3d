/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:54:02 by valentin          #+#    #+#             */
/*   Updated: 2023/06/14 17:00:33 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->win_height = WIN_HEIGHT;
	data->win_width = WIN_WIDTH;
	init_player(&data->player);
	init_textures_infos(&data->textures_infos);
	data->map = NULL;
	init_input_infos(&data->input_infos);
	/*init_img_clean(&data->minimap);
	data->texture_pixels = NULL;
	data->textures = NULL;*/
}