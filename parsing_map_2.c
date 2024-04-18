/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:23:38 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/18 14:25:34 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pre_check(t_game *g)
{
	int	i;
	int	j;

	i = g->first_line;
	while (i <= g->last_line)
	{
		j = 0;
		while (g->file.all_file[i][j])
		{
			if (g->file.all_file[i][j] != '1' && g->file.all_file[i][j] != '0'
					&& g->file.all_file[i][j] != ' '
						&& g->file.all_file[i][j] != '\n'
							&& g->file.all_file[i][j] != 'N'
								&& g->file.all_file[i][j] != 'S'
									&& g->file.all_file[i][j] != 'E'
										&& g->file.all_file[i][j] != 'W')
			{
				printf("Erreur components");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_inside(t_game *game)
{
	int	i;
	int	j;

	i = game->first_line;
	while (i <= game->last_line)
	{
		j = 0;
		while (game->file.all_file[i][j])
		{
			if (game->file.all_file[i][j] == ' ')
			{
				game->file.all_file[i][j] = '1';
			}
			j++;
		}
		i++;
	}
}

void	ft_check_inside_2(t_game *g)
{
	int	i;
	int	j;

	i = g->first_line;
	while (++i <= g->last_line)
	{
		j = 0;
		while (g->file.all_file[i][j])
		{
			if (g->file.all_file[i][j] == 'N' || g->file.all_file[i][j] == 'S'
				|| g->file.all_file[i][j] == 'W'
					|| g->file.all_file[i][j] == 'E')
			{
				g->boool++;
				g->player = g->file.all_file[i][j];
			}
			j++;
		}
	}
	if (g->boool != 1)
	{
		printf("Erreur player");
		exit(EXIT_FAILURE);
	}
}

void	ft_stock_map(t_game *g)
{
	int	i;
	int	j;

	i = g->first_line;
	j = 0;
	g->file.map = malloc(sizeof(char *) * (g->last_line - g->first_line + 2));
	while (i <= g->last_line)
	{
		g->file.map[j] = ft_strdup(g->file.all_file[i]);
		i++;
		j++;
	}
	g->file.map[j] = NULL;
}

void	ft_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file.map[i])
	{
		j = 0;
		while (game->file.map[i][j])
		{
			if (game->file.map[i][j] == 'N' || game->file.map[i][j] == 'S'
				|| game->file.map[i][j] == 'W' || game->file.map[i][j] == 'E')
			{
				game->x_player = j;
				game->y_player = i;
			}
			j++;
		}
		i++;
	}
}
