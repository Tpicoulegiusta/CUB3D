/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:05:54 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/22 16:00:19 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// void    ft_parse_path(t_game *game, int i)
// {
//     int 	j;
// 	int		start;
// 	int		end;
// 	char	*path;

// 	while(game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
// 		j++;
// 	j += 2;
// 	while(game->file.tab_txt[i][j] == ' ' || game->file.tab_txt[i][j] == '\t')
// 		j++;
// 	if(game->file.tab_txt[i][j] != '\0')
// 	{
// 		start = j;
// 		while(game->file.tab_txt[i][j] != '\0')
// 			j++;
// 		end = j;
// 		while(game->file.tab_txt[i][end] == ' ' || game->file.tab_txt[i][end] == '\t')
// 		end--;
// 	}
// 	path = ft_substr(game->file.tab_txt[i], start, end);
// }
