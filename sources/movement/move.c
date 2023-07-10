/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:00:47 by valentin          #+#    #+#             */
/*   Updated: 2023/06/29 17:17:30 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	move_player_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * 0.03;
	new_y = data->player.pos_y + data->player.dir_y * 0.03;
	return (check_move(data, new_x, new_y));
}

static int	move_player_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * 0.03;
	new_y = data->player.pos_y - data->player.dir_y * 0.03;
	return (check_move(data, new_x, new_y));
}

static int	move_player_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * 0.03;
	new_y = data->player.pos_y - data->player.dir_x * 0.03;
	return (check_move(data, new_x, new_y));
}

static int	move_player_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * 0.03;
	new_y = data->player.pos_y + data->player.dir_x * 0.03;
	return (check_move(data, new_x, new_y));
}

int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.move_y == 1)
		moved += move_player_forward(data);
	if (data->player.move_y == -1)
		moved += move_player_backward(data);
	if (data->player.move_x == -1)
		moved += move_player_left(data);
	if (data->player.move_x == 1)
		moved += move_player_right(data);
	if (data->player.rotate != 0)
		moved += rotate(data, data->player.rotate);
	return (moved);
}
