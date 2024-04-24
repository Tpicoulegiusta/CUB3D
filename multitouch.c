/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitouch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:06:31 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 16:14:43 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	multipress(t_game *game)
{
	if (game->data.up == 1)
		upp(game, game->file.map);
	if (game->data.down == 1)
		down(game, game->file.map);
	if (game->data.left == 1)
		left(game);
	if (game->data.right == 1)
		right(game);
	if (game->data.l_strafe == 1)
		l_strafing(game, game->file.map);
	if (game->data.r_strafe == 1)
		r_strafing(game, game->file.map);
}

int	ft_keypress(int key, t_game *game)
{
	if (key == 65363)
		game->data.right = 1;
	if (key == 65361)
		game->data.left = 1;
	if (key == 119)
		game->data.up = 1;
	if (key == 115)
		game->data.down = 1;
	if (key == 100)
		game->data.l_strafe = 1;
	if (key == 97)
		game->data.r_strafe = 1;
	kb_hooks(key, game);
	return (0);
}

int	ft_keyrelease(int key, t_game *game)
{
	if (key == 65363)
		game->data.right = 0;
	if (key == 65361)
		game->data.left = 0;
	if (key == 119)
		game->data.up = 0;
	if (key == 115)
		game->data.down = 0;
	if (key == 100)
		game->data.l_strafe = 0;
	if (key == 97)
		game->data.r_strafe = 0;
	return (0);
}

int	hook_loop(t_game *game)
{
	multipress(game);
	raycast(game);
	return (0);
}
