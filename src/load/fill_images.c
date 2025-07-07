/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:59:24 by miyuu             #+#    #+#             */
/*   Updated: 2025/07/07 20:53:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdint.h>
#include <unistd.h>

static uint32_t	*get_image_addr(
	uint32_t *mlx_img
)
{
	int			bpp;
	int			size_line;
	int			endian;
	uint32_t	*mlx_addr;

	mlx_addr = \
		(uint32_t *)mlx_get_data_addr(
			mlx_img,
			&bpp,
			&size_line,
			&endian);
	return (mlx_addr);
}

static void	set_img_addr(t_data *data)
{
	data->ea_img_addr = get_image_addr(data->ea_img);
	data->no_img_addr = get_image_addr(data->no_img);
	data->so_img_addr = get_image_addr(data->so_img);
	data->we_img_addr = get_image_addr(data->we_img);
	debug_dprintf(STDERR_FILENO, "%lx %lx %lx %lx\n", \
					data->ea_img_addr, \
					data->no_img_addr, \
					data->so_img_addr, \
					data->we_img_addr \
				);
}

void	*read_img_with_mlx(t_data *data, char *filename)
{
	int		fd;
	int		size;
	void	*img;

	size = IMG_SIZE;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_perror_and_exit(filename);
	close(fd);
	img = mlx_xpm_file_to_image(data->mlx, filename, &size, &size);
	if (!img)
		error_print_and_exit("mlx_xpm_file_to_image failed");
	return (img);
}

void	fill_images(t_data *data, const t_tokens_tmp *tokens)
{
	if (!(tokens->no_path && tokens->so_path && \
			tokens->we_path && tokens->ea_path))
		error_print_and_exit("Invalid path_to_texture value.");
	if (tokens && tokens->no_path)
		data->no_img = read_img_with_mlx(data, tokens->no_path);
	if (tokens && tokens->so_path)
		data->so_img = read_img_with_mlx(data, tokens->so_path);
	if (tokens && tokens->we_path)
		data->we_img = read_img_with_mlx(data, tokens->we_path);
	if (tokens && tokens->ea_path)
		data->ea_img = read_img_with_mlx(data, tokens->ea_path);
	set_img_addr(data);
}
