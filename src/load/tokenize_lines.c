/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:28:05 by miyuu             #+#    #+#             */
/*   Updated: 2025/05/25 13:42:23 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_textures_in_tokens_tmp(t_tokens_tmp	*p, const char *line)
{
	if (!p->no_path && ft_strncmp(line, "NO ", 3) == 0)
		p->no_path = trim_spaces_both_ends(&line[3]);
	else if (!p->so_path && ft_strncmp(line, "SO ", 3) == 0)
		p->so_path = trim_spaces_both_ends(&line[3]);
	else if (!p->we_path && ft_strncmp(line, "WE ", 3) == 0)
		p->we_path = trim_spaces_both_ends(&line[3]);
	else if (!p->ea_path && ft_strncmp(line, "EA ", 3) == 0)
		p->ea_path = trim_spaces_both_ends(&line[3]);
	else if (!p->f_rgb && ft_strncmp(line, "F ", 2) == 0)
		p->f_rgb = trim_spaces_both_ends(&line[2]);
	else if (!p->c_rgb && ft_strncmp(line, "C ", 2) == 0)
		p->c_rgb = trim_spaces_both_ends(&line[2]);
}

void	fill_map_in_tokens_tmp(t_tokens_tmp *p, const t_strlst *lines)
{
	size_t		y;
	size_t		map_height;

	map_height = get_trimmed_lstsize(lines);
	p->map_lines = (char **)ft_calloc(map_height + 1, sizeof(char *));
	if (!p->map_lines)
		error_perror_and_exit(NULL);
	y = 0;
	while (y < map_height && lines)
	{
		p->map_lines[y] = strdup_trim_nl(lines->str);
		y++;
		lines = lines->next;
	}
}

bool	is_cub_identifier(const char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0 \
		|| ft_strncmp(str, "SO ", 3) == 0 \
		|| ft_strncmp(str, "WE ", 3) == 0 \
		|| ft_strncmp(str, "EA ", 3) == 0 \
		|| ft_strncmp(str, "F ", 2) == 0 \
		|| ft_strncmp(str, "C ", 2) == 0)
		return (true);
	return (false);
}

t_tokens_tmp	*tokenize_lines(const t_strlst *lines)
{
	t_tokens_tmp	*tokens;
	size_t			i;
	size_t			line_num;

	tokens = (t_tokens_tmp *)ft_calloc(1, sizeof(t_tokens_tmp));
	if (!tokens)
		error_perror_and_exit(NULL);
	line_num = 0;
	while (lines)
	{
		i = 0;
		while (ft_isspace(lines->str[i]))
			i++;
		if (line_num > 5 || !is_cub_identifier(&lines->str[i]))
		{
			fill_map_in_tokens_tmp(tokens, lines);
			break ;
		}
		else
			fill_textures_in_tokens_tmp(tokens, &lines->str[i]);
		line_num++;
		lines = lines->next;
	}
	debug_print_tokens_tmp(tokens);
	return (tokens);
}
