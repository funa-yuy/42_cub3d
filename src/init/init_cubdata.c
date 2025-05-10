/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cubdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:11:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/10 18:37:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_print_data(t_data *data)
{
	size_t	y;

	printf("----------- パース後 -------------\n");
	printf("MLX pointer: %p\n", data->mlx);
	printf("北 texture: %p\n", data->no_img);
	printf("南 texture: %p\n", data->so_img);
	printf("西 texture: %p\n", data->we_img);
	printf("東 texture: %p\n", data->ea_img);
	printf("床   color: 0x%06X\n", data->f_color);
	printf("天井 color: 0x%06X\n", data->c_color);
	printf("Player position: x = %u, y = %u, dir = %c\n", data->player.x, data->player.y, data->player.dir);
	printf("以下、mapデータ: %s\n", data->map ? "あり↓" : "なし(null)");
	y = 0;
	while (data->map && data->map[y] != NULL)
	{
		printf("%s\n", data->map[y]);
		y++;
	}
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

	if (!color)
		return (0);//todo: debugのために、一旦exitせずに終わる
	rgb = ft_split(color, ',');//todo: 一旦", "で区切られてる前提でやってる、もっと細かいparse関数を作る
	if (!rgb)
	{
		// exit(ERR_SYSCALL);
		return (0);//todo: debugのために、一旦exitせずに終わる
	}
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

void	init_player_position(t_data *data)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (data->map && data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' \
				|| data->map[y][x] == 'S' \
				|| data->map[y][x] == 'E' \
				|| data->map[y][x] == 'W')
			{
				data->player = (t_pos){y, x, data->map[y][x]};
				//playerが正しく存在する前提なので。プレイヤー見つかったら終わる。ちゃんといるかをここで再度判定するのもあり
				return ;
			}
			x++;
		}
		y++;
	}
}

void	fill_map(t_data *d, char **map_lines)
{
	size_t		y;
	size_t		map_height;

	if (!map_lines || !map_lines[0])//もし、空行だったらexitする todo:正規化の段階でからだったらエラー吐くようにする?
	{
		//todo : free
		// exit(ERROR);todo: debugのために、一旦exitせずに終わる
		return ;
	}
	map_height = 0;
	while (map_lines[map_height])
		map_height++;
	d->map = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!d->map)
		exit(ERR_SYSCALL);
	y = 0;
	while (map_lines[y])
	{
		d->map[y] = ft_strdup(map_lines[y]);
		y++;
	}
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
	fill_map(data, parsed->map_lines);//todo: ここでmapのバリデートする?
	// if (!data->map)todo: debugのために、一旦exitしない
	// 	exit(ERR_SYSCALL);
	init_player_position(data);//todo: もし、プレイヤーがぞんざいしなかったらエラー(mapバリデートでやっちゃう？)
	init_images(data, parsed);
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
