/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:03:30 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:30:13 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destarray;
	const char	*srcarray;
	size_t		i;

	destarray = (char *)dest;
	srcarray = (char *)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			destarray[i] = srcarray[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n > 0)
		{
			destarray[n - 1] = srcarray[n - 1];
			n--;
		}
	}
	return (dest);
}
