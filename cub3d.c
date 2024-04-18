/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/18 12:56:50 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	ft_exit(t_game *game, char *str)
{
	printf("%s\n", str);
	ft_free_tab(game->file.tab_txt);
	exit(EXIT_FAILURE);
}

void	ft_exit_2(t_game *game, char *str)
{
	printf("%s\n", str);
	ft_free_tab(game->file.tab_txt);
	ft_free_tab(game->file.all_file);
	ft_free_obj(game);
	exit(EXIT_FAILURE);
}


void	ft_free_obj(t_game *game)
{
	if (game->data.no)
		free(game->data.no);
	if (game->data.so)
		free(game->data.so);
	if (game->data.we)
		free(game->data.we);
	if (game->data.ea)
	 	free(game->data.ea);
	if (game->data.f)
		free(game->data.f);
	if (game->data.c)
		free(game->data.c);
}

void	ft_innit(t_game *game)
{
	game->bol = 0;
	game->n_no = 0;
	game->n_so = 0;
	game->n_ea = 0;
	game->n_we = 0;
	game->no_pos = 0;
	game->so_pos = 0;
	game->we_pos = 0;
	game->ea_pos = 0;
	game->n_f = 0;
	game->n_c = 0;
	game->f_pos = 0;
	game->c_pos = 0;
	game->tab_i = 0;
	game->last_line = 0;
	game->first_line = 0;
	game->x_player = 0;
	game->y_player = 0;
	game->bool = 0;
	game->boool = 0;
	game->size_max = 0;
	game->long_line = 0;
	game->look = 0;
	game->last_line_2 = 0;
	game->first_line_2 = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	ft_innit(&game);
	ft_innit_obj(&game);
	if (ft_parsing(argc, argv, &game) != 0)
		return (1);
	ft_void_reunit(&game);
    // while(game.file.map[i])
	// {
	// 	printf("'%s'\n", game.file.map[i]);	
	// 	//ft_free_tab(game.file.all_file);
	// 	i++;
	// }
	ft_freez(&game);
}
