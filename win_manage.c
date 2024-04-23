/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:03:53 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 14:33:27 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit_win(t_game *game)
{
	int	i;

	i = -1;
	while (game->file.map[++i])
		free(game->file.map[i]);
	free(game->file.map);
	exit(0);
}

int	kb_hooks(int key, t_game *game)
{
	int	i;

	if (key == 65307)
	{
		i = -1;
		while (game->file.map[++i])
			free(game->file.map[i]);
		free(game->file.map);
		game->file.map = NULL;
		exit(0);
	}
	return (0);
}

void	hooks(t_game *game)
{
	mlx_hook(game->data.mlx_win, 17, 0, quit_win, game);
	mlx_hook(game->data.mlx_win, 2, 1L << 0, ft_keypress, game);
	mlx_hook(game->data.mlx_win, 3, 1L << 1, ft_keyrelease, game);
	mlx_loop_hook(game->data.mlx, hook_loop, game);
}
