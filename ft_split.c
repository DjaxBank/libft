/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:55:30 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:30:44 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*freestrings(char **newstrings)
{
	size_t	i;

	i = 0;
	while (newstrings[i] != NULL)
	{
		free(newstrings[i]);
		i++;
	}
	free(newstrings);
	return (NULL);
}

static size_t	countstrings(char const *s, char c, size_t i)
{
	size_t	strings;

	strings = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			strings++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (strings);
}

static char	**makememory(char const *s, char c, char **newstrings, size_t i)
{
	int		p;
	size_t	lastlim;

	p = 0;
	lastlim = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			lastlim = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			newstrings[p] = malloc((i - lastlim + 1) * sizeof(char));
			if (newstrings[p] == NULL)
				return (freestrings(newstrings));
			p++;
			while (s[i] == c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	newstrings[p] = NULL;
	return (newstrings);
}

static char	**fillstrings(char **newstrings, char const *s, char c, size_t i)
{
	size_t	j;
	size_t	p;

	j = 0;
	p = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			newstrings[p][j] = '\0';
			p++;
			j = 0;
			while (s[i] == c && s[i] != '\0')
				i++;
		}
		else
		{
			newstrings[p][j] = s[i];
			i++;
			j++;
		}
	}
	if (j > 0)
		newstrings[p][j] = '\0';
	return (newstrings);
}

char	**ft_split(char const *s, char c)
{
	char	**newstrings;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	newstrings = malloc((countstrings(s, c, i) + 1) * sizeof(char *));
	if (newstrings == NULL)
		return (NULL);
	newstrings = makememory(s, c, newstrings, i);
	if (newstrings == NULL)
		return (NULL);
	return (fillstrings(newstrings, s, c, i));
}
