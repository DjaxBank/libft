/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:25:18 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:31:04 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	p;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	p = 0;
	if (size == 0)
		return (srclen);
	else if (size <= dstlen)
		return (size + srclen);
	while (i < size - 1 && p < srclen)
	{
		dst[i] = src[p];
		i++;
		p++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
