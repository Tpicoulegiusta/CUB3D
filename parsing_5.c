/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:05:54 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/26 16:37:20 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_pos(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->file.tab_txt[i])
	{
		j = 0;
		while (g->file.tab_txt[i][j] == ' ' || g->file.tab_txt[i][j] == '\t')
			j++;
		if (g->file.tab_txt[i][j] == 'N')
			g->no_pos = i;
		if (g->file.tab_txt[i][j] == 'S')
			g->so_pos = i;
		if (g->file.tab_txt[i][j] == 'W')
			g->we_pos = i;
		if (g->file.tab_txt[i][j] == 'E')
			g->ea_pos = i;
		i++;
	}
}

void	ft_check_path(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == ' ' || path[i] == '\t')
		{
			printf("error path\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char	*ft_parse_path(t_game *g, int i, int j)
{
	int		start;
	int		end;
	char	*path;

	while (g->file.tab_txt[i][j] == ' ' || g->file.tab_txt[i][j] == '\t')
		j++;
	j += 2;
	while (g->file.tab_txt[i][j] == ' ' || g->file.tab_txt[i][j] == '\t')
		j++;
	if (g->file.tab_txt[i][j] != '\0')
	{
		start = j;
		while (g->file.tab_txt[i][j] != '\0')
			j++;
		end = j - 1;
		while (g->file.tab_txt[i][end] == ' '
			|| g->file.tab_txt[i][end] == '\t')
			end--;
		path = ft_substr(g->file.tab_txt[i], start, (end - start) + 1);
		ft_check_path(path);
		return (path);
	}
	else
		ft_exit_2(g, "erreur path\n");
	return (NULL);
}
