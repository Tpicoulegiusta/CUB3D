/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:03:25 by tpicoule          #+#    #+#             */
/*   Updated: 2024/03/15 14:10:52 by tpicoule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_counti(char *s, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (s[i] == c)
		i++;
	if (s[0] != c || s[i + 1] == '\0')
		k++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	if (s[0] == c && k > 0)
		k++;
	return (k);
}

char	**ft_countj(char **tabtab, char *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			tabtab [x] = ft_substr(s, j, i - j);
			x++;
		}
	}
	tabtab [x] = NULL;
	return (tabtab);
}

char	**ft_split(char *s, char c)
{
	char	**tabtab;

	if (!s)
	{
		tabtab = malloc(sizeof(char) * 1);
		if (!tabtab)
			return (0);
		tabtab[0] = 0;
		return (tabtab);
	}
	tabtab = malloc(sizeof(char *) * (ft_counti(s, c) + 1));
	if (!tabtab)
		return (0);
	tabtab = ft_countj(tabtab, s, c);
	return (tabtab);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s1;
	//int		i;
	int		j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) > len + 1)
		s1 = malloc(sizeof(char) * len + 1);
	else
		s1 = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	if (!s1)
		return (NULL);
	//i = start;
	j = 0;
	while (j < len && s[start])
	{
		s1[j] = s[start];
		j++;
		start++;
	}
	s1[j] = '\0';
	return (s1);
}

char	*ft_strdup(char *source)
{
	int		i;
	char	*str1;

	str1 = malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (i < ft_strlen(source))
	{
	str1[i] = source[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}