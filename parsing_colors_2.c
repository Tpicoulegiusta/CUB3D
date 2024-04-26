/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:38 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/26 16:36:56 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_one(char *t_p_color)
{
	int	i;

	i = 0;
	while (t_p_color[i])
	{
		while (t_p_color[i] && (t_p_color[i] == ' ' || t_p_color[i] == '\t'))
			i++;
		while (t_p_color[i] && ft_isdigit(t_p_color[i]) == 1)
			i++;
		while (t_p_color[i] && (t_p_color[i] == ' ' || t_p_color[i] == '\t'))
			i++;
		if (t_p_color[i] && t_p_color[i] != '\0')
		{
			printf("Error t_p_color\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_rgb_f_c(int nbr, t_game *game)
{
	game->file.rgb_f_c[game->tab_i] = nbr;
	game->tab_i++;
}

void	ft_check_nbr(int nbr, t_game *game)
{
	if (nbr < 0 || nbr > 255)
	{
		printf("Error path colors\n");
		exit(EXIT_FAILURE);
	}
	ft_rgb_f_c(nbr, game);
}

void	ft_valid_color(char *tab_p_color, t_game *game)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = -1;
	while (tab_p_color[i])
	{
		while (tab_p_color[i] && (tab_p_color[i] == ' '
				|| tab_p_color[i] == '\t'))
			i++;
		if (tab_p_color[i] && (ft_isdigit(tab_p_color[i]) == 1))
			nbr = ft_atoi(&tab_p_color[i]);
		while (tab_p_color[i] && (ft_isdigit(tab_p_color[i]) == 1))
			i++;
		while (tab_p_color[i] && (tab_p_color[i] == ' '
				|| tab_p_color[i] == '\t'))
			i++;
	}
	ft_check_nbr(nbr, game);
}

void	ft_check_tree(char *path, t_game *game)
{
	char	**tab_p_colors;
	int		i;

	i = 0;
	tab_p_colors = ft_split(path, ',');
	while (tab_p_colors[i])
	{
		ft_check_one(tab_p_colors[i]);
		ft_valid_color(tab_p_colors[i], game);
		i++;
	}
	if (i != 3)
	{
		printf("Error path colors\n");
		exit(EXIT_FAILURE);
	}
	ft_free_tab(tab_p_colors);
}
