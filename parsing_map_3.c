/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:26:31 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/11 16:51:57 by tpicoule         ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	j = 0;
	while(game->file.cpy_map[i])
	{
		j = 0;
		while(game->file.cpy_map[i][j])
		{
			if (game->file.cpy_map[i][j] == '0')
				ft_check_z(game, i, j);
			j++;
		}
		i++;
	}
}

void	ft_create_cpy(t_game *game)
{
	int i;
	int	j;
	int	k;
	int count;

	k = 0;
	i = 0;
	j = 0;
	count = 0;
	while(game->file.map[i])
		i++;
	game->file.cpy_map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (game->file.map[i])
	{
		j = 0;
		k = 0;
		game->file.cpy_map[i] = malloc(sizeof(char) * (game->long_line + 1));
		while(game->file.map[i][k])
		{
			while(game->file.map[i][k])
			{
				game->file.cpy_map[i][j] = game->file.map[i][k];
				j++;
				k++;
			}
			while (j < game->long_line)
			{
				game->file.cpy_map[i][j] = 'x';
				j++;
			}
			game->file.cpy_map[i][j] = '\0';
		}
		i++;
	}
	game->file.cpy_map[i] = NULL;
	return;
}

void	ft_alex(t_game *game)
{
	int i;
	int j;
	int k;
	
	i = 0;
	k = 0;
	while(game->file.map[i])
	{
		j = 0;
		while(game->file.map[i][j])
			j++;
		if (k < j)
			k = j;
		i++;
	}
	game->long_line = k;
	//ft_alex_2(game, i);
    puts("ooooooh");
	//ft_alex_3(game, i);
}

// void	ft_create_cpy(t_game *game)
// {
// 	int		i;

// 	i = 0;
// 	while (game->file.map[i])
// 		i++;
// 	game->file.cpy_map = malloc(sizeof(char *) * (i + 1));
// 	i = 0;
// 	while (game->file.map[i])
// 	{
// 		game->file.cpy_map[i] = ft_strdup(game->file.map[i]);
// 		i++;
// 	}
// 	game->file.cpy_map[i] = NULL;
// 	return;
// }
// void	ft_virus(t_game *game, int x, int y)
// {
//     if (game->file.cpy_map[y][x] != game->player && game->file.cpy_map[y][x] != '0')
//         return ;
//     game->file.cpy_map[y][x] = 'X';
//     // for (int i = 0;game->file.cpy_map[i]; i++)
//     // {
//     //     printf("cpymap[%d] -> '%s'\n", i, game->file.cpy_map[i]);
//     // }
//     // printf("-----------\n");
// 	ft_virus(game, x + 1, y);
// 	ft_virus(game, x, y + 1);
// 	ft_virus(game, x - 1, y);
// 	ft_virus(game, x, y - 1);
// 	return ;
// }

// void    ft_inside_walls(t_game *game)
// {
//     // for (int x = 0;game->file.cpy_map[x]; x++)
//     //     printf("cpymap[%d] -> '%s'\n", x, game->file.cpy_map[x]);
//     ft_virus(game, game->x_player, game->y_player);
//         // for (int x = 0;game->file.cpy_map[x]; x++)
//         // printf("cpymap[%d] -> '%s'\n", x, game->file.cpy_map[x]);
// }

// void	ft_alex_2(t_game *game, int k)
// {
// 	int i;
	
// 	i = 0;
// 	//printf("k == %d\n i == %d\n", k, i);
// 	game->file.cpy_cpy = malloc(sizeof(char *) * k + 1);
// 	while(i <= k)
// 	{
// 		game->file.cpy_cpy[i] = malloc(sizeof(char) * (game->long_line + 1));
// 		game->file.cpy_cpy[i] = game->file.cpy_map[i];
// 		printf("'%s'\n", game->file.cpy_cpy[i]);
// 		i++;
// 	}
// 	//game->file.cpy_cpy[i] = NULL;
//     //puts("aaaaaaaaaaaaah");
// }
