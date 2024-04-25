/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:40:20 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/25 15:15:01 by tpicoule         ###   ########.fr       */
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
	if (game->data.tex_n.path)
		free(game->data.tex_n.path);
	if (game->data.tex_s.path)
		free(game->data.tex_s.path);
	if (game->data.tex_w.path)
		free(game->data.tex_w.path);
	if (game->data.tex_e.path)
		free(game->data.tex_e.path);
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
	game->flag = 0;
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
	// int x = 0;
	// while(game.tab_tab[x])
	// {
	// 	printf("map == '%s'\n", game.tab_tab[x]);
	// 	x++;
	// }
	// //reddy/////////////////////////////////////////
	data_init(&game);
	window(&game);
	tex_init(&game.data.tex_n, game.data.mlx);
	tex_init(&game.data.tex_s, game.data.mlx);
	tex_init(&game.data.tex_e, game.data.mlx);
	tex_init(&game.data.tex_w, game.data.mlx);
	raycast(&game);
	hooks(&game);
	mlx_loop(game.data.mlx);
	ft_freez(&game);
}
