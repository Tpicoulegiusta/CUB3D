/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_2_save_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:16:26 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/15 13:46:32 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parse_f(t_game *g, int i, int j)
{
	while (g->file.tab_colors[++i])
	{
		j = 0;
		while (g->file.tab_colors[i][j] && (g->file.tab_colors[i][j] == ' '
			|| g->file.tab_colors[i][j] == '\t'))
			j++;
		if (g->file.tab_colors[i][j] == 'F'
			&& g->file.tab_colors[i][j + 1] == ' ')
		{
			if (g->file.tab_colors[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(g, "file problems_file_txt_no_colors\n");
		}
		while (g->file.tab_colors[i][j] && (g->file.tab_colors[i][j] == ' '
			|| g->file.tab_colors[i][j] == '\t'))
			j++;
		if (g->file.tab_colors[i][j] == '\0')
			ft_exit(g, "file problems_file_txt_no_colors\n");
	}
}

void	ft_parse_c(t_game *g, int i, int j)
{
	while (g->file.tab_colors[++i])
	{
		j = 0;
		while (g->file.tab_colors[i][j] && (g->file.tab_colors[i][j] == ' '
			|| g->file.tab_colors[i][j] == '\t'))
			j++;
		if (g->file.tab_colors[i][j] == 'C'
			&& g->file.tab_colors[i][j + 1] == ' ')
		{
			if (g->file.tab_colors[i][j + 2] != '\0')
				j += 2;
			else
				ft_exit(g, "file problems_file_txt_no_colors\n");
		}
		while (g->file.tab_colors[i][j] && (g->file.tab_colors[i][j] == ' '
			|| g->file.tab_colors[i][j] == '\t'))
			j++;
		if (g->file.tab_colors[i][j] == '\0')
			ft_exit(g, "file problems_file_txt_no_colors\n");
	}
}
