/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:38 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/03 16:39:54 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_atoi_me_pls(char	**tab_p_colors)
// {
// 	int	i;
	
// 	i = 0;
// 	while(tab_p_colors[i])
// 	{
// 		if (ft_atoi(tab_p_colors[i]) < 0 || ft_atoi(tab_p_colors[i]) >= 255)
// 			i++;
// 		else
// 		{
// 			printf("Erreur path colors_digit_atoi\n");
// 			exit(EXIT_FAILURE);
// 		}
// 	}
// }

void	ft_check_one(char  *tab_p_color)
{
	int i;

	i = 0;
	printf("tab == '%s'\n", tab_p_color);
	while (tab_p_color[i])
	{
		while(tab_p_color[i] && (tab_p_color[i] == ' ' || tab_p_color[i] == '\t'))
			i++;
		while(tab_p_color[i] && ft_isdigit(tab_p_color[i]) == 1)
			i++;
		while(tab_p_color[i] && (tab_p_color[i] == ' ' || tab_p_color[i] == '\t'))
			i++;
		if (tab_p_color[i] && tab_p_color[i] != '\0')
		{
			printf("Erreur tab_p_color colorz\n");
	 		exit(EXIT_FAILURE);
		}
	}
}

void	ft_check_nbr(nbr)
{
	if (nbr < 0 || nbr > 255)
	{
		printf("Erreur path colorsss\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_valid_color(char *tab_p_color)
{
	int i;
	int	nbr;

	i = 0;
	nbr = -1;
	while(tab_p_color[i])
	{
		while( tab_p_color[i] && (tab_p_color[i] == ' ' || tab_p_color[i] == '\t'))
			i++;
		if (tab_p_color[i] && (ft_isdigit(tab_p_color[i]) == 1))
			nbr = ft_atoi(&tab_p_color[i]);
		while(tab_p_color[i] && (ft_isdigit(tab_p_color[i]) == 1))
			i++;
		while(tab_p_color[i] && (tab_p_color[i] == ' ' || tab_p_color[i] == '\t'))
			i++;
	}
	ft_check_nbr(nbr);
}

void	ft_check_tree(char *path)
{
	char	**tab_p_colors;
	int i;

	i = 0;
	tab_p_colors = ft_split(path, ',');
	// printf("tab_colors === '%s'\n", tab_p_colors[0]);
	// printf("tab_colors === '%s'\n", tab_p_colors[1]);
	// printf("tab_colors === '%s'\n", tab_p_colors[2]);
	// printf("tab_colors === '%s'\n", tab_p_colors[3]);
	puts("caca");
	while(tab_p_colors[i])
	{
		ft_check_one(tab_p_colors[i]);
		ft_valid_color(tab_p_colors[i]);
		i++;
	}
	if (i != 3)
	{
		printf("Erreur path colorsss\n");
		exit(EXIT_FAILURE);
	}
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


void	ft_check_path_f_c(char *path)
{
	int	i;

	i = 0;
	ft_check_two(path);
	ft_check_tree(path);
	puts("caca");
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
