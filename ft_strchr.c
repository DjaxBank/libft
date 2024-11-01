/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:45:20 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:30:48 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	else
	{
		while (s[i] != '\0')
		{
			i++;
			if ((unsigned char)s[i] == (unsigned char)c)
				return ((char *)&s[i]);
		}
	}
	return (NULL);
}
