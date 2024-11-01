/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:36:45 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:40:01 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	size_t	p;

	p = 0;
	while (c != set[p])
	{
		p++;
		if (c == set[p])
			return (1);
		else if (set[p] == '\0')
			return (0);
	}
	return (1);
}

static	size_t	first_limit(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (check_set(s1[i], set) == 0)
			return (i);
		i++;
	}
	return (i);
}

static size_t	second_limit(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	while (i > 0)
	{
		if (check_set(s1[i], set) == 0)
			return (i);
		i--;
	}
	return (i);
}

char	*fill_newstr(char const *s1, char *newstr, size_t *pos)
{
	size_t	i;
	size_t	j;

	j = pos[0];
	i = 0;
	while (j <= pos[1])
	{
		newstr[i] = s1[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	pos[2];
	char	*newstr;

	if (s1[0] == '\0' || s1 == NULL)
		return (ft_strdup(""));
	if (set[0] == '\0' || set == NULL)
		return (ft_strdup(s1));
	pos[0] = first_limit(s1, set);
	pos[1] = second_limit(s1, set);
	if (pos[1] < pos[0])
		return (ft_strdup(""));
	newstr = malloc((pos[1] - pos[0] + 2) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	return (fill_newstr(s1, newstr, pos));
}
