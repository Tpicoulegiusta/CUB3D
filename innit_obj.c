/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:54:18 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/24 18:38:51 by tpicoule         ###   ########.fr       */
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

	i = 0;
	j = 0;
	while (game->file.map[i])
	{
		if (game->file.map[i][j] == '0')
		{
			printf("Error_map\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
