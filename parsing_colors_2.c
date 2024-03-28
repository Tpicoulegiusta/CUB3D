/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:38 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/28 16:36:52 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_tree(char *path)
{
	char	**tab_p_colors;
	int i;

	i = 0;
	tab_p_colors = malloc(sizeof(char *) * (3 + 1));
	tab_p_colors = ft_split(path, ',');
	printf("tab_colors === %s\n", tab_p_colors[0]);
	printf("tab_colors === %s\n", tab_p_colors[1]);
	printf("tab_colors === %s\n", tab_p_colors[2]);
	printf("tab_colors === %s\n", tab_p_colors[3]);
	ft_free_tab(tab_p_colors);
}

void	ft_check_2_bis(char *path)
{
	int i;
	
	i = 0;
	while(path[i])
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
	int i;
	int	count;

	i = 0;
	count = 0;
	while(path[i])
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

void	ft_check_one(char *path)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(path[i])
	{
		if (ft_isdigit(path[i]) == 1 || ft_isalpha(path[i]) == 1)
			count++;
		i++;
	}
	if (count < 5 || count > 11)
	{
		printf("Erreur path colors\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_path_f_c(char *path)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	ft_check_one(path);
	ft_check_two(path);
	ft_check_tree(path);
}

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
	    path = ft_substr(g->file.tab_colors[i], start, (end - start) + 1);
        printf("path === '%s'\n", path);
		puts("caca");
		ft_check_path_f_c(path);
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
