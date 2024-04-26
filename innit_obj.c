/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:54:18 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/26 16:35:07 by tpicoule         ###   ########.fr       */
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

	i = 0;
	while (game->file.map[i])
	{
		j = 0;
		while (game->file.map[i][j])
			j++;
		if (game->file.map[i][j - 1] && game->file.map[i][j - 1] != '1')
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

	i = game->first_line;
	j = 0;
	k = 0;
	j = game->last_line_2 - game->first_line_2 + 1;
	i = 0;
	while (game->file.map[i])
		i++;
	if (j != i)
	{
		printf("Error_map\n");
		exit(EXIT_FAILURE);
	}
}
