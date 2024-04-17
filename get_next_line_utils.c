/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:53:28 by tpicoule          #+#    #+#             */
/*   Updated: 2024/04/12 14:01:04 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		n;

	result = malloc((sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	n = 0;
	if (!s2)
		return (free(result), NULL);
	while (s1[i])
		result[n++] = s1[i++];
	i = 0;
	while (s2[i])
		result[n++] = s2[i++];
	result[n] = '\0';
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		x;

	x = 0;
	str = malloc(size * count + 1);
	if (!str)
		return (NULL);
	if (size && __SIZE_MAX__ / size < count)
		return (free(str), NULL);
	while (x < count * size)
	{
		str[x] = 0;
		x++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int rd)
{
	size_t	i;
	size_t	j;

	if (!str)
		return (NULL);
	j = ft_strlen(str);
	i = 0;
	while (i < j + 1)
	{
		if (str[i] == (char) rd)
			return (&((char *) str)[i + 1]);
		i++;
	}
	return (NULL);
}

char	*ft_substr2(char *s, int start, int end)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = start;
	ret = malloc((end - start + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < end - start)
		ret[i++] = s[j++];
	ret[i] = '\0';
	if (start > 0)
		free(s);
	return (ret);
}
