/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:55:43 by valentin          #+#    #+#             */
/*   Updated: 2023/06/12 19:56:02 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_input_infos(t_input_infos *input_infos)
{
	input_infos->filepath = NULL;
	input_infos->filetab = NULL;
	input_infos->fd = 0;
	input_infos->nb_of_lines = 0;
	input_infos->height = 0;
	input_infos->width = 0;
	input_infos->index_end_of_map = 0;
}