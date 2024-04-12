/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multitouch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbulanad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:47:20 by rbulanad          #+#    #+#             */
/*   Updated: 2024/04/12 14:15:27 by rbulanad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	multipress(t_data *data)
{
	if (data->up == 1)
		upp(data, data->map);
	if (data->down == 1)
		down(data, data->map);
	if (data->left == 1)
		left(data);
	if (data->right == 1)
		right(data);
	if (data->l_strafe == 1)
		l_strafing(data, data->map);
	if (data->r_strafe == 1)
		r_strafing(data, data->map);
}

int	ft_keypress(int key, t_data *data)
{
	if (key == 100)
		data->right = 1;
	if (key == 97)
		data->left = 1;
	if (key == 119)
		data->up = 1;
	if (key == 115)
		data->down = 1;
	if (key == 101)
		data->l_strafe = 1;
	if (key == 113)
		data->r_strafe = 1;
	kb_hooks(key, data);
	return (0);
}

int	ft_keyrelease(int key, t_data *data)
{
	if (key == 100)
		data->right = 0;
	if (key == 97)
		data->left = 0;
	if (key == 119)
		data->up = 0;
	if (key == 115)
		data->down = 0;
	if (key == 101)
		data->l_strafe = 0;
	if (key == 113)
		data->r_strafe = 0;
	return (0);
}

int	hook_loop(t_data *data)
{
	multipress(data);
	raycast(data);
	return (0);
}
