/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:01:25 by rbulanad          #+#    #+#             */
/*   Updated: 2024/03/20 18:01:06 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit_win(void)
{
	exit(0);
}

int	kb_hooks(int key)
{
	if (key == 65307)
		exit(0);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 2, 1L << 0, &movement, data);
	mlx_key_hook(data->mlx_win, kb_hooks, data);
	mlx_hook(data->mlx_win, 17, 0, quit_win, data);
}