/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:26:31 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 16:29:37 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_z(t_game *game, int i, int j)
{
	if (game->file.cpy_map[i][j + 1] == 'x'
		|| game->file.cpy_map[i - 1][j] == 'x'
			|| game->file.cpy_map[i + 1][j] == 'x')
	{
		printf("Error open_map\n");
		ft_free_tab(game->file.cpy_map);
		exit(EXIT_FAILURE);
	}
}

void	ft_z_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->file.cpy_map[i])
	{
		j = 0;
		while (game->file.cpy_map[i][j])
		{
			if (game->file.cpy_map[i][j] == '0'
				|| game->file.cpy_map[i][j] == game->player)
				ft_check_z(game, i, j);
			j++;
		}
		i++;
	}
}

void	ft_create_cpy(t_game *game, int i, int j, int k)
{
	int	count;

	count = 0;
	while (game->file.map[i])
		i++;
	game->file.cpy_map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (game->file.map[i])
	{
		j = 0;
		k = 0;
		game->file.cpy_map[i] = malloc(sizeof(char) * (game->long_line + 1));
		while (game->file.map[i][k])
		{
			while (game->file.map[i][k])
				game->file.cpy_map[i][j++] = game->file.map[i][k++];
			while (j < game->long_line)
				game->file.cpy_map[i][j++] = 'x';
			game->file.cpy_map[i][j] = '\0';
		}
		i++;
	}
	game->file.cpy_map[i] = NULL;
	return ;
}

void	ft_alex(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (game->file.map[i])
	{
		j = 0;
		while (game->file.map[i][j])
			j++;
		if (k < j)
			k = j;
		i++;
	}
	game->long_line = k;
}
