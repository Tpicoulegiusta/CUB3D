/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:31:22 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 13:40:19 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_look_at_me(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < game->first_line)
    {
        j = 0;
        while(game->file.all_file[i][j] == ' '  || game->file.all_file[i][j] == '\t')
            j++;
        if (game->file.all_file[i][j] != '\0' && game->file.all_file[i][j + 1]
			&& (ft_isprint(game->file.all_file[i][j + 1]) == 1))
			game->look++;
		i++;
    }
	if (game->look != 6)
	{
		printf("Error too much line\n");
		exit(EXIT_FAILURE);
	}
}
