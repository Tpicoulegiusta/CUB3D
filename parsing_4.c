/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:53:07 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/21 16:17:20 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_parse_texture(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(game->file.tab_txt[i])
    {
        j = 0;
        while(game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
			j++;
		if(game->file.tab_txt[i][j] == 'N' && game->file.tab_txt[i][j + 1] == 'O')
			game->n_NO++;
		if(game->file.tab_txt[i][j] == 'S' && game->file.tab_txt[i][j + 1] == 'O')
			game->n_SO++;
		if(game->file.tab_txt[i][j] == 'W' && game->file.tab_txt[i][j + 1] == 'E')
			game->n_WE++;
		if(game->file.tab_txt[i][j] == 'E' && game->file.tab_txt[i][j + 1] == 'A')
			game->n_EA++;
		i++;
    }
	if (game->n_NO != 1 || game->n_SO != 1 || game->n_WE != 1 || game->n_EA != 1)
		{
			printf("file problems_txtzzzzzzz\n");
			exit(EXIT_FAILURE);
		}
/////////////check_xpm///////////
	i = 0;
	j = 0;
	while(game->file.tab_txt[i])
	{
		j = 0;
		while(game->file.tab_txt[i][j] && (game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t'))
			j++;
		if(game->file.tab_txt[i][j] == 'N' && game->file.tab_txt[i][j + 1] == 'O')
		{
			j + 2;
			while(game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
			j++;
		}
		
	}
}
