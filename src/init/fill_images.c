/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:59:24 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/11 23:59:22 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*read_img_with_mlx(t_data *data, char *filename)
{
	int		fd;
	int		size;
	void	*img;

	size = IMG_SIZE;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		//todo : free
		error_perror_and_exit(filename);
	}
	close(fd);
	img = mlx_xpm_file_to_image(data->mlx, filename, &size, &size);
	if (!img)
	{
		//todo : free
		error_print_and_exit("mlx_xpm_file_to_image failed");
	}
	return (img);
}

void	fill_images(t_data *data, const t_tokens_tmp *tokens)
{
	//todo: 本来は、tokenizeでpathがNULLな場合のエラー処理するので、ここでは必要ない
	if (!(tokens->no_path && tokens->so_path && tokens->we_path && tokens->ea_path))
	{
		//todo; free
		error_print_and_exit("Invalid path_to_texture value.");
	}
	if (tokens && tokens->no_path)
		data->no_img = read_img_with_mlx(data, tokens->no_path);
	if (tokens && tokens->so_path)
		data->so_img = read_img_with_mlx(data, tokens->so_path);
	if (tokens && tokens->we_path)
		data->we_img = read_img_with_mlx(data, tokens->we_path);
	if (tokens && tokens->ea_path)
		data->ea_img = read_img_with_mlx(data, tokens->ea_path);
}
