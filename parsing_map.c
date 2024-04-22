/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:38:07 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/22 13:28:27 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reducer(t_game *game)
{
	(void)game;
	printf("Erreur map_1_smthing down here or missing map\n");
	exit(EXIT_FAILURE);
}

void	ft_last_line(t_game *g, int j)
{
	int	i;

	i = g->size_tab;
	while (--i > 0)
	{
		j = 0;
		while (g->file.all_file[i][j])
		{
			while (g->file.all_file[i][j] == ' '
				|| g->file.all_file[i][j] == '\t')
				j++;
			if (g->file.all_file[i][j] == '\n'
				|| g->file.all_file[i][j] == '\0')
				break ;
			else if (g->file.all_file[i][j] == '1')
			{
				g->last_line = i;
				return ;
			}
			else
				ft_reducer(g);
		}
	}
}

void	ft_first_line(t_game *game, int j)
{
	int	i;

	i = 0;
	while (i < game->last_line)
	{
		j = 0;
		while (game->file.all_file[i][j])
		{
			while (game->file.all_file[i][j] == ' '
				|| game->file.all_file[i][j] == '\t')
				j++;
			if (game->file.all_file[i][j] == '\n' ||
					game->file.all_file[i][j] == '\0' ||
						(ft_isprint(game->file.all_file[i][j]) == 1 &&
							game->file.all_file[i][j] != '1'))
				break ;
			else if (game->file.all_file[i][j] == '1')
			{
				game->first_line = i;
				return ;
			}
		}
		i++;
	}
}

void	ft_check_line(char *str)
{
	int	j;

	j = 0;
	while (str[j] == ' ' || str[j] == '1')
		j++;
	if (str[j] != '\0' && str[j] != '\n')
	{
		printf("Error on line map1\n");
		exit(EXIT_FAILURE);
	}
}

int	ft_cara(int i)
{
	if (i == 'N')
		return (0);
	if (i == 'S')
		return (0);
	if (i == 'W')
		return (0);
	if (i == 'E')
		return (0);
	return (1);
}
