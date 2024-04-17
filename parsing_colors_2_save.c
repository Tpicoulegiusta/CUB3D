/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_2_save.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:14:16 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 14:23:47 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_2_bis(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (path[i] == ',' && path[i + 1] == ',')
		{
			printf("Erreur path colorsss\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_check_two(char *path)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (path[i])
	{
		if (path[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		printf("Erreur path colorss\n");
		exit(EXIT_FAILURE);
	}
	ft_check_2_bis(path);
}

void	ft_check_path_f_c(char *path, t_game *game)
{
	int	i;

	i = 0;
	ft_check_two(path);
	ft_check_tree(path, game);
}

char	*ft_parse_path_f_c(t_game *g, int i, int j)
{
	int		start;
	int		end;
	char	*path;

	while (g->file.tab_colors[i][j] == ' ' || g->file.tab_colors[i][j] == '\t')
		j++;
	j += 1;
	while (g->file.tab_colors[i][j] == ' ' || g->file.tab_colors[i][j] == '\t')
		j++;
	if (g->file.tab_colors[i][j] != '\0')
	{
		start = j;
		while (g->file.tab_colors[i][j] != '\0')
			j++;
		end = j - 1;
		while (g->file.tab_colors[i][end] == ' '
			|| g->file.tab_colors[i][end] == '\t')
			end--;
		path = ft_substr(g->file.tab_colors[i], start, (end - start) + 1);
		ft_check_path_f_c(path, g);
		return (path);
	}
	else
		ft_exit_2(g, "erreur path\n");
	return (NULL);
}

void	ft_parse_f_c_pos(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->file.tab_colors[i])
	{
		j = 0;
		while (g->file.tab_colors[i][j] == ' '
			|| g->file.tab_colors[i][j] == '\t')
			j++;
		if (g->file.tab_colors[i][j] == 'F')
			g->f_pos = i;
		if (g->file.tab_colors[i][j] == 'C')
			g->c_pos = i;
		i++;
	}
}
