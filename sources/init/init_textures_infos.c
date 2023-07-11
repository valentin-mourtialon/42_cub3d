/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmourtia <vmourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:57:05 by valentin          #+#    #+#             */
/*   Updated: 2023/07/11 12:59:56 by vmourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_textures_infos(t_textures_infos *textures_infos)
{
	textures_infos->no = NULL;
	textures_infos->so = NULL;
	textures_infos->we = NULL;
	textures_infos->ea = NULL;
	textures_infos->f = 0;
	textures_infos->c = 0;
	textures_infos->hex_floor = 0x0;
	textures_infos->hex_ceiling = 0x0;
	textures_infos->size = 64;
	textures_infos->step = 0.0;
	textures_infos->pos = 0.0;
	textures_infos->x = 0;
	textures_infos->y = 0;
}
