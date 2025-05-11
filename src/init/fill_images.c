/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 20:59:24 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/11 15:56:49 by mfunakos         ###   ########.fr       */
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
		// exit(ERR_SYSCALL);
		return (NULL);//todo: debugのために、一旦exitせずにnullを返す
	}
	close(fd);
	img = mlx_xpm_file_to_image(data->mlx, filename, &size, &size);
	if (!img)
	{
		// exit(ERROR);
		return (NULL);//todo: debugのために、一旦exitせずにnullを返す
	}
	return (img);
}

void	fill_images(t_data *data, const t_tokens_tmp *tokens)
{
	if (tokens && tokens->no_path)
		data->no_img = read_img_with_mlx(data, tokens->no_path);
	if (tokens && tokens->so_path)
		data->so_img = read_img_with_mlx(data, tokens->so_path);
	if (tokens && tokens->we_path)
		data->we_img = read_img_with_mlx(data, tokens->we_path);
	if (tokens && tokens->ea_path)
		data->ea_img = read_img_with_mlx(data, tokens->ea_path);
}
