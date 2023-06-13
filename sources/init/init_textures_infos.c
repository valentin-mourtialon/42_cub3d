/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:57:05 by valentin          #+#    #+#             */
/*   Updated: 2023/06/13 15:36:47 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures_infos(t_textures_infos *textures_infos)
{
	textures_infos->NO = NULL;
	textures_infos->SO = NULL;
	textures_infos->WE = NULL;
	textures_infos->EA = NULL;
	textures_infos->F = 0;
	textures_infos->C = 0;
	/*textures_infos_infos->hex_floor = 0x0;
	textures_infos->hex_ceiling = 0x0;
	textures_infos->size = TEX_SIZE;
	textures_infos->step = 0.0;
	textures_infos->pos = 0.0;
	textures_infos->x = 0;
	textures_infos->y = 0;*/
}
