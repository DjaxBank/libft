/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:31:12 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:30:07 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*srcarray;
	char			*destarray;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	srcarray = (char *)src;
	destarray = (char *)dest;
	while (i < n)
	{
		destarray[i] = srcarray[i];
		i++;
	}
	return (dest);
}
