/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:41:59 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:30:52 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstring;
	size_t	i;
	size_t	p;

	i = ft_strlen(s);
	p = 0;
	newstring = malloc((i + 1) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	while (p < i)
	{
		newstring[p] = s[p];
		p++;
	}
	newstring[p] = '\0';
	return (newstring);
}
