/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:35:54 by valentin          #+#    #+#             */
/*   Updated: 2023/06/29 14:00:10 by sel-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

static unsigned int	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned int	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

static int	check_xpm_file(char *filename)
{
	int		filename_length;
	int		extension_length;
	int		fd;

	if (is_directory(filename))
		return (throw_error_msg(INVALID_ARG, filename, DIRECTORY), 0);
	filename_length = ft_strlen(filename);
	extension_length = ft_strlen(XPM);
	if (filename_length <= extension_length)
		return (throw_error_msg(INVALID_FILENAME, filename, SHORT_FILENAME), 0);
	if (ft_strcmp(&filename[filename_length - extension_length], XPM))
		return (throw_error_msg(INVALID_FILENAME, filename,
				INVALID_EXTENSION), 0);
	if (!is_valid_filename(filename))
		return (throw_error_msg(INVALID_FILENAME, filename,
				SPECIAL_CHARACTERS), 0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (throw_error_msg(NULL, filename, strerror(errno)), 0);
	close(fd);
	return (1);
}

int	check_textures(t_data *data, t_textures_infos *textures)
{
	if (!textures->NO || !textures->SO || !textures->WE || !textures->EA)
		return (0);
	if (!textures->F || !textures->C)
		return (0);
	if (check_xpm_file(textures->NO) == 0
		|| check_xpm_file(textures->SO) == 0
		|| check_xpm_file(textures->WE) == 0
		|| check_xpm_file(textures->EA) == 0
		|| check_valid_rgb(textures->F) == 0
		|| check_valid_rgb(textures->C) == 0)
		return (0);
	textures->hex_floor = convert_rgb_to_hex(textures->F);
	textures->hex_ceiling = convert_rgb_to_hex(textures->C);
	return (1);
}
