/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:28:05 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/09 17:28:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup_trim_nl(const char *str)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		len--;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (len > i)
	{
		dst[i] = str[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

void	fill_parse_tmp(t_parse_tmp	*p, const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		p->no_path = ft_strdup_trim_nl(&line[3]);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		p->so_path = ft_strdup_trim_nl(&line[3]);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		p->we_path = ft_strdup_trim_nl(&line[3]);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		p->ea_path = ft_strdup_trim_nl(&line[3]);
	else if (ft_strncmp(line, "F ", 2) == 0)
		p->f_rgb = ft_strdup_trim_nl(&line[2]);
	else if (ft_strncmp(line, "C ", 2) == 0)
		p->c_rgb = ft_strdup_trim_nl(&line[2]);
}

void	fill_map_lines(t_parse_tmp *p, const t_strlst *lines)
{
	size_t		y;
	size_t		map_height;

	if (!lines || !lines->str)//もし、空行だったらexitする todo:正規化の段階でからだったらエラー吐くようにする?
	{
		//todo : free
		exit(ERR_FILE);
	}
	map_height = str_lstsize(lines);
	p->map_lines = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!p->map_lines)
		exit(ERR_SYSCALL);
	y = 0;
	while (lines)
	{
		p->map_lines[y++] = ft_strdup_trim_nl(lines->str);
		lines = lines->next;
	}
}

t_parse_tmp	*tokenize_lines(const t_strlst *lines)
{
	t_parse_tmp	*parsed;

	parsed = (t_parse_tmp *)ft_calloc(1, sizeof(t_parse_tmp));
	if (!parsed)
		exit(ERR_SYSCALL);
	while (lines)
	{
		if (ft_strncmp(lines->str, "NO ", 3) == 0 \
			|| ft_strncmp(lines->str, "SO ", 3) == 0 \
			|| ft_strncmp(lines->str, "WE ", 3) == 0 \
			|| ft_strncmp(lines->str, "EA ", 3) == 0 \
			|| ft_strncmp(lines->str, "F ", 2) == 0 \
			|| ft_strncmp(lines->str, "C ", 2) == 0)
			fill_parse_tmp(parsed, lines->str);
		else
		{
			//識別子に当てはまらなかったら、それ以降を全部mapとして判定する
			fill_map_lines(parsed, lines);
			break ;//todo: mapは最後の要素のはずなので、map格納が終わったらbreakする？
		}
		lines = lines->next;
	}
	debug_print_parse_tmp(parsed);
	return (parsed);
}
