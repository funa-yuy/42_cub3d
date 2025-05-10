/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 17:26:32 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_data(t_data *data)
{
	int	y;

	printf("----------- パース後 -------------\n");
	printf("MLX pointer: %p\n", data->mlx);
	// printf("Player position: x = %u, y = %u\n", data->player.x, data->player.y);
	printf("以下、mapデータ: %s\n", data->map ? "あり↓" : "なし(null)");
	y = 0;
	while (data->map && data->map[y] != NULL)
	{
		printf("%s\n", data->map[y]);
		y++;
	}
	// printf("北 texture: %p\n", data->no_img);
	// printf("南 texture: %p\n", data->so_img);
	// printf("西 texture: %p\n", data->we_img);
	// printf("東 texture: %p\n", data->ea_img);
	printf("床   color: 0x%06X\n", data->f_color);
	printf("天井 color: 0x%06X\n", data->c_color);
	printf("---------------------------------\n\n");
}

void	*read_img_with_mlx(t_data *data, char *filename)
{
	int		fd;
	int		size;
	void	*img;

	size = IMG_SIZE;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(ERR_SYSCALL);
	close(fd);
	img = mlx_xpm_file_to_image(data->mlx, filename, &size, &size);
	if (!img)
		exit(ERROR);
	return (img);
}

void	init_images(t_data *data, const t_parse_tmp *parsed)
{
	data->no_img = read_img_with_mlx(data, parsed->no_path);
	data->so_img = read_img_with_mlx(data, parsed->so_path);
	data->we_img = read_img_with_mlx(data, parsed->we_path);
	data->ea_img = read_img_with_mlx(data, parsed->ea_path);
}

int	rgb_to_hex(char *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(color, ',');
	if (!rgb)
		exit(ERR_SYSCALL);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	init_color(t_data *data, const t_parse_tmp *parsed)
{
	data->f_color = rgb_to_hex(parsed->f_rgb);
	data->c_color = rgb_to_hex(parsed->c_rgb);
}

t_data	*parse_to_data(const t_parse_tmp *parsed)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(ERR_SYSCALL);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(ERROR);
	data->map = parsed->map_lines;//todo: ここでmapのバリデートする?
	if (!data->map)
		exit(ERR_SYSCALL);
	// init_player_position(data);//todo: もし、プレイヤーがぞんざいしなかったらエラー(mapバリデートでやっちゃう？)
	// init_images(data, parsed);
	init_color(data, parsed);
	debug_print_data(data);
	return (data);
}

t_data	*init_cubdata(char *file)
{
	t_data				*data;
	const t_strlst		*lines_list;
	const t_parse_tmp	*parsed;

	// 正規化：strlst に格納
	lines_list = NULL;
	lines_list = normalize_cubdata(file);

	// トーカナイズ：中間構造体への格納(parse_temp)に格納
	//todo parse_tempをtokens_tmpに命名変更する
	parsed = NULL;
	parsed = tokenize_lines(lines_list);
	// todo: free_strlst(lines_list);

	// パース：構造体に格納
	data = parse_to_data(parsed);
	// todo: free_parse_tmp(parsed);
	return (data);
}
