/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:25 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/12 14:15:48 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit_win(t_data *data)
{
	int	i;

	i = -1;
	while (++i < MAPWIDTH)
		free(data->map[i]);
	free(data->map);
	exit(0);
}

int	kb_hooks(int key, t_data *data)
{
	int	i;

	if (key == 65307)
	{
		i = -1;
		while (++i < MAPWIDTH)
			free(data->map[i]);
		free(data->map);
		data->map = NULL;
		exit(0);
	}
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 17, 0, quit_win, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, ft_keypress, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, ft_keyrelease, data);
	mlx_loop_hook(data->mlx, hook_loop, data);
}
