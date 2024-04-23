/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   innit_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:54:18 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/23 14:39:59 by tpicoule         ###   ########.fr       */
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
