/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:05:54 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/25 17:01:57 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/////no argv[1] etc.../////

void    ft_num_path(t_game *game, int i, int j)
{
    printf("c->%c\n", game->file.tab_txt[i][j]);
    if (game->file.tab_txt[i][j] == 'N')
        game->no_pos = i;
    else if (game->file.tab_txt[i][j] == 'S')
        game->so_pos = i;        
    else if (game->file.tab_txt[i][j] == 'W')
        game->we_pos = i;
    else if (game->file.tab_txt[i][j] == 'E')
        game->ea_pos = i;         
}

void    ft_parse_path(t_game *game, int i)
{
    int 	j;
	int		start;
	int		end;
	char	*path;

    j = 0;
	while(game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
		j++;
    ft_num_path(game, i, j);
	j += 2;
	while(game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
		j++;
	if(game->file.tab_txt[i][j] != '\0')
	{
		start = j;
		while(game->file.tab_txt[i][j] != '\0')
        {
            //////reparer + path a mieux check ===> str avant ou apres mal fait/////////
            // if (game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
            // {
            //     printf("HELLO");
            //     exit(EXIT_FAILURE);
            // }
            j++;
        }
        end = j;
		while(game->file.tab_txt[i][end] == ' ' || game->file.tab_txt[i][end] == '\t')
		end--;
	    path = ft_substr(game->file.tab_txt[i], start, end);
       printf("path === %s\n", path);
	}
}
