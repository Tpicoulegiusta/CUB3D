/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:52:03 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/26 14:58:01 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Y' a t il le bon nombre d'arguments ++ la map est elle un .cub\0//
int check_args(int argc, char **argv)
{
    int i;
    
    if (argc != 2)
        return (1);
    i = ft_strlen(argv[1]) - 4;
	while (i < ft_strlen(argv[1]) + 1)
	{
        if (argv[1][i++] != '.')
			return(1);
		if (argv[1][i++] != 'c')
			return(1);
		if (argv[1][i++] != 'u')
			return(1);		
        if (argv[1][i++] != 'b')
			return(1);		
		if (argv[1][i++] != '\0')
			return(1);
	}
	return(0);
}

//la map est elle un fichier ouvrable ou non ++ la map est elle un dossier//
int open_file(char **argv)
{
    int can;
    int directory;
    
    directory = open(argv[1], __O_DIRECTORY, 0777);
    can = open(argv[1], O_RDONLY, 0777);
    if (can == -1 || directory != -1)
        return (1);
    return (0);
    }