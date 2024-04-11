/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:23:38 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/09 16:51:29 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_pre_check(t_game *g)
{
    int i;
    int j;
    
    i = g->first_line;
    while(i <= g->last_line)
    {
        j = 0;
        while(g->file.all_file[i][j])
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
void    ft_check_inside(t_game *game)
{
    int i;
    int j;

    i = game->first_line;
    while(i <= game->last_line)
    {
        j = 0;
        while(game->file.all_file[i][j])
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

void    ft_check_inside_2(t_game *game)
{
    int i;
    int j;

    i = game->first_line;
    while(++i <= game->last_line)
    {
        j = 0;
        while(game->file.all_file[i][j])
        {
            if (game->file.all_file[i][j] == 'N' || game->file.all_file[i][j] == 'S'
                || game->file.all_file[i][j] == 'W' || game->file.all_file[i][j] == 'E')
                {
                    game->boool++;
					game->player = game->file.all_file[i][j];
                }
            j++;
        }
    }
    if (game->boool != 1)
    {
        printf("Erreur player");
		exit(EXIT_FAILURE);
    }
}

void	ft_stock_map(t_game *game)
{
	int i;
	int j;

	i = game->first_line;
	j = 0;
	game->file.map = malloc(sizeof(char *) * (game->last_line -game->first_line + 2));
	while(i <= game->last_line)
	{
		game->file.map[j] = ft_strdup(game->file.all_file[i]);
		i++;
		j++;
	}
	game->file.map[j] = NULL;
}

void	ft_player(t_game *game)
{
	int i;
	int j;

	i = 0;
	while(game->file.map[i])
	{
		j = 0;
        while(game->file.map[i][j])
        {
            if (game->file.map[i][j] == 'N' || game->file.map[i][j] == 'S'
                || game->file.map[i][j] == 'W' || game->file.map[i][j] == 'E')
                {
                    game->x_player = j;
                    game->y_player = i;
                    printf("x = %d, y = %d\n", game->x_player, game->y_player);
                }
            j++;
        }
		i++;
	}
}
