/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:53:07 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 14:08:24 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_texture(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->file.tab_txt[++i])
	{
		j = 0;
		while (g->file.tab_txt[i][j] == ' ' || g->file.tab_txt[i][j] == '\t')
			j++;
		if (g->file.tab_txt[i][j] == 'N' && g->file.tab_txt[i][j + 1] == 'O')
			g->n_no++;
		if (g->file.tab_txt[i][j] == 'S' && g->file.tab_txt[i][j + 1] == 'O')
			g->n_so++;
		if (g->file.tab_txt[i][j] == 'W' && g->file.tab_txt[i][j + 1] == 'E')
			g->n_we++;
		if (g->file.tab_txt[i][j] == 'E' && g->file.tab_txt[i][j + 1] == 'A')
			g->n_ea++;
	}
	if (g->n_no != 1 || g->n_so != 1 || g->n_we != 1 || g->n_ea != 1)
		ft_exit(g, "file problems_file_txt");
	ft_parse_no(g, -1, 0);
	ft_parse_so(g, -1, 0);
	ft_parse_we(g, -1, 0);
	ft_parse_ea(g, -1, 0);
}

void	ft_parse_no(t_game	*game, int i, int j)
{
	while (game->file.tab_txt[++i])
	{
		j = 0;
		while (game->file.tab_txt[i][j] && (game->file.tab_txt[i][j] == ' '
			|| game->file.tab_txt[i][j] == '\t'))
			j++;
		if (game->file.tab_txt[i][j] == 'N'
			&& game->file.tab_txt[i][j + 1] == 'O')
		{
			if (game->file.tab_txt[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(game, "file problems_file_txt_no_path\n");
			if (game->file.tab_txt[i][j] == ' '
				|| game->file.tab_txt[i][j] == '\t')
			{
				while (game->file.tab_txt[i][j] == ' '
					|| game->file.tab_txt[i][j] == '\t')
					j++;
			}
			else
				ft_exit(game, "file problems_file_txt_no_path_no_space\n");
		}
	}
}

void	ft_parse_so(t_game	*game, int i, int j)
{
	while (game->file.tab_txt[++i])
	{
		j = 0;
		while (game->file.tab_txt[i][j] && (game->file.tab_txt[i][j] == ' '
			|| game->file.tab_txt[i][j] == '\t'))
			j++;
		if (game->file.tab_txt[i][j] == 'S'
			&& game->file.tab_txt[i][j + 1] == 'O')
		{
			if (game->file.tab_txt[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(game, "file problems_file_txt_no_path\n");
			if (game->file.tab_txt[i][j] == ' '
				|| game->file.tab_txt[i][j] == '\t')
			{
				while (game->file.tab_txt[i][j] == ' '
					|| game->file.tab_txt[i][j] == '\t')
					j++;
			}
			else
				ft_exit(game, "file problems_file_txt_no_path_no_space\n");
		}
	}
}

void	ft_parse_we(t_game	*game, int i, int j)
{
	while (game->file.tab_txt[++i])
	{
		j = 0;
		while (game->file.tab_txt[i][j] && (game->file.tab_txt[i][j] == ' '
			|| game->file.tab_txt[i][j] == '\t'))
			j++;
		if (game->file.tab_txt[i][j] == 'W'
			&& game->file.tab_txt[i][j + 1] == 'E')
		{
			if (game->file.tab_txt[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(game, "file problems_file_txt_no_path\n");
			if (game->file.tab_txt[i][j] == ' '
				|| game->file.tab_txt[i][j] == '\t')
			{
				while (game->file.tab_txt[i][j] == ' '
					|| game->file.tab_txt[i][j] == '\t')
					j++;
			}
			else
				ft_exit(game, "file problems_file_txt_no_path_no_space\n");
		}
	}
}

void	ft_parse_ea(t_game	*game, int i, int j)
{
	while (game->file.tab_txt[++i])
	{
		j = 0;
		while (game->file.tab_txt[i][j] && (game->file.tab_txt[i][j] == ' '
			|| game->file.tab_txt[i][j] == '\t'))
			j++;
		if (game->file.tab_txt[i][j] == 'E'
			&& game->file.tab_txt[i][j + 1] == 'A')
		{
			if (game->file.tab_txt[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(game, "file problems_file_txt_no_path\n");
			if (game->file.tab_txt[i][j] == ' '
				|| game->file.tab_txt[i][j] == '\t')
			{
				while (game->file.tab_txt[i][j] == ' '
					|| game->file.tab_txt[i][j] == '\t')
					j++;
			}
			else
				ft_exit(game, "file problems_file_txt_no_path_no_space\n");
		}
	}
}
