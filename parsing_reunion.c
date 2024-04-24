/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_reunion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:46:08 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/24 18:28:04 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_void_reunit(t_game *game)
{
	ft_parse_colors(game);
	ft_last_line(game, 0);
	ft_first_line(game, 0);
	ft_look_at_me(game);
	ft_check_line(game->file.all_file[game->first_line]);
	ft_check_line(game->file.all_file[game->last_line]);
	ft_pre_check(game);
	ft_check_inside(game);
	ft_check_inside_2(game);
	ft_stock_map(game);
	ft_player(game);
	ft_alex(game);
	ft_create_cpy(game, 0, 0, 0);
	ft_z_check(game);
	ft_repair(game);
	ft_last_line_2(game);
	ft_first_line_2(game);
	ft_last_man(game);
	ft_another_check(game);
}

void	ft_freez(t_game *game)
{
	ft_free_tab(game->file.all_file);
	ft_free_tab(game->file.tab_txt);
	ft_free_tab(game->file.tab_colors);
	ft_free_tab(game->file.map);
	ft_free_tab(game->file.cpy_map);
	free(game->file.tab1);
	ft_free_tab(game->tab_tab);
	ft_free_obj(game);
}
