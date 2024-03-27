/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:38 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/27 18:35:29 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *ft_parse_path_f_c(t_game *g, int i, int j)
{
	int		start;
	int		end;
	char	*path;

	while(g->file.tab_colors[i][j] == ' ' || g->file.tab_colors[i][j] == '\t')
		j++;
	j += 1;
	while(g->file.tab_colors[i][j] == ' ' || g->file.tab_colors[i][j] == '\t')
		j++;
	if(g->file.tab_colors[i][j] != '\0')
	{
		start = j;
		while(g->file.tab_colors[i][j] != '\0')
            j++;
        end = j - 1;
		while(g->file.tab_colors[i][end] == ' ' || g->file.tab_colors[i][end] == '\t')
			end--;
	    path = ft_substr(g->file.tab_colors[i], start, (end - start) + 1);//peut etre mal free???//
		//ft_check_path(path);//AAAAA FAAAAAAIIIIIIIRRRRRREEEEE/////
        printf("path === '%s'\n", path);
		return (path);
	}
	else
		ft_exit_2(g, "erreur path\n");
	return (NULL);
}

void	ft_parse_f_c_pos(t_game *g)
{
	int i;
	int j;

	i = 0;
	while(g->file.tab_colors[i])
	{
		j = 0;
		while(g->file.tab_colors[i][j] == ' ' || g->file.tab_colors[i][j] == '\t')
			j++;
		if(g->file.tab_colors[i][j] == 'F')
			g->f_pos = i;
		if(g->file.tab_colors[i][j] == 'C')
			g->c_pos = i;
		i++;
	}
}

void	ft_parse_f(t_game *game, int i, int j)
{
	while(game->file.tab_colors[++i])
	{
		j = 0;
		while(game->file.tab_colors[i][j] && (game->file.tab_colors[i][j] == ' '
			|| game->file.tab_colors[i][j] == '\t'))
			j++;
		if(game->file.tab_colors[i][j] == 'F'
			&& game->file.tab_colors[i][j + 1] == ' ')
		{
			if(game->file.tab_colors[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(game, "file problems_file_txt_no_colors\n");
		}
    	while(game->file.tab_colors[i][j] && (game->file.tab_colors[i][j] == ' '
			|| game->file.tab_colors[i][j] == '\t'))
			j++;
        if (game->file.tab_colors[i][j] == '\0')
				ft_exit(game, "file problems_file_txt_no_colors\n");
	}
}

void	ft_parse_c(t_game *game, int i, int j)
{
	while(game->file.tab_colors[++i])
	{
		j = 0;
		while(game->file.tab_colors[i][j] && (game->file.tab_colors[i][j] == ' '
			|| game->file.tab_colors[i][j] == '\t'))
			j++;
		if(game->file.tab_colors[i][j] == 'C'
			&& game->file.tab_colors[i][j + 1] == ' ')
		{
			if(game->file.tab_colors[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(game, "file problems_file_txt_no_colors\n");
		}
    	while(game->file.tab_colors[i][j] && (game->file.tab_colors[i][j] == ' '
			|| game->file.tab_colors[i][j] == '\t'))
			j++;
        if (game->file.tab_colors[i][j] == '\0')
				ft_exit(game, "file problems_file_txt_no_colors\n");
	}
}
