/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:03:08 by valentin          #+#    #+#             */
/*   Updated: 2023/06/29 10:38:50 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_img_data(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
}

void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_data(image);
	image->img = mlx_new_image(data->mlx, width, height);
	if (image->img == NULL)
		exit_program(data, 1);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_data(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path,
			&data->textures_infos.size,
			&data->textures_infos.size);
	if (image->img == NULL)
		exit_program(data, 1);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_program(data, 1);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
		exit_program(data, 1);
}
