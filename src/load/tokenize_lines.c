/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:28:05 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/24 16:06:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*strdup_trim_nl(const char *str)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		len--;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		error_perror_and_exit(NULL);
	i = 0;
	while (len > i)
	{
		dst[i] = str[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

char	*trim_spaces_both_ends(const char *str)
{
	char	*dst;
	size_t	start;
	size_t	end;
	size_t	j;
	size_t	len;

	start = 0;
	while (ft_isspace(str[start]))
		start++;
	end = ft_strlen(str);
	while (end > start && ft_isspace(str[end - 1]))
		end--;
	len = end - start;
	dst = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dst)
		error_perror_and_exit(NULL);
	j = 0;
	while (len > j)
	{
		dst[j] = str[start + j];
		j++;
	}
	dst[len] = '\0';
	return (dst);
}

void	fill_textures_in_tokens_tmp(t_tokens_tmp	*p, const char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		p->no_path = trim_spaces_both_ends(&line[3]);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		p->so_path = trim_spaces_both_ends(&line[3]);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		p->we_path = trim_spaces_both_ends(&line[3]);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		p->ea_path = trim_spaces_both_ends(&line[3]);
	else if (ft_strncmp(line, "F ", 2) == 0)
		p->f_rgb = trim_spaces_both_ends(&line[2]);
	else if (ft_strncmp(line, "C ", 2) == 0)
		p->c_rgb = trim_spaces_both_ends(&line[2]);
}

void	fill_map_in_tokens_tmp(t_tokens_tmp *p, const t_strlst *lines)
{
	size_t		y;
	size_t		map_height;

	//もし、空行だったらexitする todo:正規化の段階で空だったらエラー吐くようにする
	map_height = str_lstsize(lines);
	p->map_lines = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!p->map_lines)
		error_perror_and_exit(NULL);
	y = 0;
	while (lines)
	{
		p->map_lines[y++] = strdup_trim_nl(lines->str);
		lines = lines->next;
	}
}

t_tokens_tmp	*tokenize_lines(const t_strlst *lines)
{
	t_tokens_tmp	*tokens;
	size_t			i;

	tokens = (t_tokens_tmp *)ft_calloc(1, sizeof(t_tokens_tmp));
	if (!tokens)
		error_perror_and_exit(NULL);

	while (lines)
	{
		i = 0;
		while (ft_isspace(lines->str[i]))
			i++;
		if (ft_strncmp(&lines->str[i], "NO ", 3) == 0 \
			|| ft_strncmp(&lines->str[i], "SO ", 3) == 0 \
			|| ft_strncmp(&lines->str[i], "WE ", 3) == 0 \
			|| ft_strncmp(&lines->str[i], "EA ", 3) == 0 \
			|| ft_strncmp(&lines->str[i], "F ", 2) == 0 \
			|| ft_strncmp(&lines->str[i], "C ", 2) == 0)
			fill_textures_in_tokens_tmp(tokens, &lines->str[i]);
		else
		{
			//todo: 6行目以降はmapとして認識する　正規化の時と同じことやる
			//識別子に当てはまらなかったら、それ以降を全部mapとして判定する
			fill_map_in_tokens_tmp(tokens, lines);
			//todo: mapは最後の要素のはずなので、map格納が終わったらbreakする？
			break ;
		}
		lines = lines->next;
	}
	debug_print_tokens_tmp(tokens);
	return (tokens);
}
