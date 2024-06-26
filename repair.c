/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repair.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:46:53 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/26 16:31:27 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_repair(t_game *game)
{
	int		i;
	int		j;
	int		start;

	i = -1;
	game->nb_line = 0;
	while (game->file.tab1[++i])
		if (game->file.tab1[i] == '\n')
			game->nb_line++;
	if (game->file.tab1[i] == '\0' && game->file.tab1[i - 1] != '\n')
		game->nb_line++;
	game->tab_tab = malloc(sizeof(char *) * (game->nb_line + 1));
	i = -1;
	j = 0;
	while (++i < game->nb_line)
	{
		start = j;
		while (game->file.tab1[j] != '\n' && game->file.tab1[j] != '\0')
			j++;
		game->tab_tab[i] = malloc(sizeof(char) * (j - start + 2));
		j++;
	}
	ft_reduce_2(game);
}

void	ft_last_line_2(t_game *game)
{
	int	i;
	int	j;

	i = game->nb_line;
	while (i > 0)
	{
		j = 0;
		while (game->tab_tab[i] && game->tab_tab[i][j])
		{
			j = 0;
			while (game->tab_tab[i][j] == ' ' || game->tab_tab[i][j] == '\t')
				j++;
			if (game->tab_tab[i][j] == '\n')
			{
				i--;
				continue ;
			}
			else
			{
				game->last_line_2 = i;
				return ;
			}
		}
		i--;
	}
}

void	ft_first_line_2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= game->last_line_2)
	{
		j = 0;
		while (game->tab_tab[i][j] == ' ')
			j++;
		if (game->tab_tab[i][j + 1] && game->tab_tab[i][j] != '1')
		{
			i++;
			continue ;
		}
		if (game->tab_tab[i][j + 1] && game->tab_tab[i][j] == '1')
		{
			game->first_line_2 = i;
			return ;
		}
		i++;
	}
}

void	ft_last_man(t_game *game)
{
	int	i;
	int	j;

	i = game->first_line_2;
	j = 0;
	while (i <= game->last_line_2)
	{
		if (game->tab_tab[i][j] == '\n' || game->tab_tab[i][j] == '\0')
		{
			printf("Error_space_between\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
