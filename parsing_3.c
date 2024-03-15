/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 11:10:59 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/15 16:06:46 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_file(char **argv, t_game *game)
{
    int		file;
    char	*tab;
	char	*tab2;
	int		i;

	i = 0;
    file = open(argv[1], O_RDONLY, 0777);
	tab = get_next_line(file);
	while(1)
	{
		i++;
		tab2 = get_next_line(file);
		if (!tab2)
			break;
		tab = ft_strjoinfree2(tab, tab2);
		free(tab2);
	}
	game->file.all_file = ft_split(tab, '\n');
	free(tab);
	if (i == 0)
		return (1);
    return (0);
}
