/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:54:18 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/25 17:18:51 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_innit_obj(t_game *game)
{
	game->data.tex_n.path = NULL;
	game->data.tex_s.path = NULL;
	game->data.tex_w.path = NULL;
	game->data.tex_e.path = NULL;
	game->data.f = NULL;
	game->data.c = NULL;
}

void	ft_another_check(t_game *game)
{
	int	i;
	int	j;

	i = game->first_line_2;
	j = 0;
	while (i <= game->last_line_2)
	{
		if (game->tab_tab[i][j] == '0' || game->tab_tab[i][j] == 'S'
			|| game->tab_tab[i][j] == 'N' || game->tab_tab[i][j] == 'W'
				|| game->tab_tab[i][j] == 'E')
		{
			printf("Error_map\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_another_check_2(t_game *game)
{
	int	i;
	int	j;

	i = game->first_line_2;
	while (i <= game->last_line_2)
	{
		j = 0;
		while (game->tab_tab[i][j] != '\n')
			j++;
		if (game->tab_tab[i][j - 1] != '1')
		{
			printf("Error_map\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_brandon_validate(t_game *game)
{
	int	i;
	int	j;
	int	k;

	//i = game->first_line;
	j = 0;
	k = 0;
	printf("first_line_2 %d\n", game->first_line_2);
	printf("last_line_2 %d\n", game->last_line_2);
	int x = game->first_line_2;
	while (game->tab_tab[x])
	{
		printf("-- '%s'\n", game->tab_tab[x]);
		x++;
	}
	printf("-- '%s'\n", game->tab_tab[x]);
	x = 0;
	while (game->file.map[x])
	{
		printf("++ '%s'\n", game->file.map[x]);
		x++;
	}
	//printf("first_line=%d\tlast_line=%d\tnb_line=%d\n", game->first_line_2, game->last_line_2, game->nb_line);
	j = game->last_line_2 - game->first_line_2 + 1;
	i = 0;
	while (game->file.map[i])
		i++;
	printf("i => %d\n", i);
	printf("j => %d\n", j);
	if (j != i)
	{
		printf("Error_map\n");
		exit(EXIT_FAILURE);
	}
}
