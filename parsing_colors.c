/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:25:21 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/24 13:29:15 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_colors(t_game *game)
{
	ft_search_colors(game);
	ft_parsing_colors(game);
	ft_parse_f_c_pos(game);
	game->data.f = ft_parse_path_f_c(game, game->f_pos, 0);
	game->data.c = ft_parse_path_f_c(game, game->c_pos, 0);
}

void	ft_first_check(t_game *g, int i, int j, int *k)
{
	while (g->file.all_file[i][j] && (*k) < 2)
	{
		if (g->file.all_file[i][j] == 'F' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == ' ')
			g->file.tab_colors[(*k)++] = ft_strdup(g->file.all_file[i]);
		else if (g->file.all_file[i][j] == 'C' && g->file.all_file[i][j + 1]
				&& g->file.all_file[i][j + 1] == ' ')
			g->file.tab_colors[(*k)++] = ft_strdup(g->file.all_file[i]);
		j++;
	}
}

void	other_check(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->file.all_file[++i])
	{
		j = 0;
		while (g->file.all_file[i][j])
		{
			if (g->file.all_file[i][j] == 'F' && g->file.all_file[i][j + 1]
					&& g->file.all_file[i][j + 1] == ' ')
				g->flag++;
			else if (g->file.all_file[i][j] == 'C' && g->file.all_file[i][j + 1]
					&& g->file.all_file[i][j + 1] == ' ')
				g->flag++;
			j++;
		}
	}
}

void	ft_search_colors(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	game->file.tab_colors = malloc(sizeof(char *) * (2 + 1));
	while (game->file.all_file[i])
	{
		j = 0;
		ft_first_check(game, i, j, &k);
		i++;
	}
	game->file.tab_colors[k] = NULL;
	other_check(game);
	if (game->flag != 2)
	{
		ft_free_tab(game->file.all_file);
		ft_free_tab(game->file.tab_txt);
		ft_free_tab(game->file.tab_colors);
		write(2, "Error\nfile problems_colors\n", 27);
		exit(EXIT_FAILURE);
	}
}

void	ft_parsing_colors(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->file.tab_colors[++i])
	{
		j = 0;
		while (g->file.tab_colors[i][j] == ' '
			|| g->file.tab_colors[i][j] == '\t')
			j++;
		if (g->file.tab_colors[i][j] == 'F'
			&& g->file.tab_colors[i][j + 1] == ' ')
			g->n_f++;
		if (g->file.tab_colors[i][j] == 'C'
			&& g->file.tab_colors[i][j + 1] == ' ')
			g->n_c++;
	}
	if (g->n_f != 1 || g->n_c != 1)
		ft_exit(g, "file problems_file_colors1");
	ft_parse_f(g, -1, 0);
	ft_parse_c(g, -1, 0);
}
