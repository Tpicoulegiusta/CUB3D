/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:59 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/18 14:28:31 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_count_lines(char **all_file)
{
	int	i;

	i = 0;
	while (all_file[i])
		i++;
	return (i);
}

int	parse_file(char **argv, t_game *game)
{
	int		file;
	char	*tab2;
	int		i;

	i = 0;
	file = open(argv[1], O_RDONLY, 0777);
	game->file.tab1 = get_next_line(file);
	while (1)
	{
		i++;
		tab2 = get_next_line(file);
		if (!tab2)
			break ;
		game->file.tab1 = ft_strjoinfree2(game->file.tab1, tab2);
		free(tab2);
	}
	if (game->file.tab1 == NULL)
		return (1);
	game->file.all_file = ft_split(game->file.tab1, '\n');
	if (i == 0)
		return (1);
	game->size_tab = ft_count_lines(game->file.all_file);
	return (0);
}

int	ft_parse_file_2(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (game->file.all_file[i])
	{
		j = 0;
		while (game->file.all_file[i][j])
		{
			if (game->file.all_file[i][j] != ' '
				&& game->file.all_file[i][j] != '\t'
					&& game->file.all_file[i][j] != '\n')
				k++;
			j++;
		}
		i++;
	}
	if (k == 0)
		return (1);
	return (0);
}

void	ft_save_line(t_game *g, int i, int j, int *k)
{
	while (g->file.all_file[i][j] && (*k) < 4)
	{
		if (g->file.all_file[i][j] == 'N' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'O')
			g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if (g->file.all_file[i][j] == 'S' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'O')
			g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if (g->file.all_file[i][j] == 'W' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'E')
			g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if (g->file.all_file[i][j] == 'E' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == 'A')
			g->file.tab_txt[(*k)++] = ft_strdup(g->file.all_file[i]);
		j++;
	}
}

void	last_check(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->file.all_file[++i])
	{
		j = 0;
		while (g->file.all_file[i][j])
		{
			if (g->file.all_file[i][j] == 'N' && g->file.all_file[i][j + 1]
					&& g->file.all_file[i][j + 1] == 'O')
				g->bol++;
			else if (g->file.all_file[i][j] == 'S' && g->file.all_file[i][j + 1]
					&& g->file.all_file[i][j + 1] == 'O')
				g->bol++;
			else if (g->file.all_file[i][j] == 'W' && g->file.all_file[i][j + 1]
					&& g->file.all_file[i][j + 1] == 'E')
				g->bol++;
			else if (g->file.all_file[i][j] == 'E' && g->file.all_file[i][j + 1]
					&& g->file.all_file[i][j + 1] == 'A')
				g->bol++;
			j++;
		}
	}
}
