/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:53:35 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:30:18 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*array;
	size_t			i;

	i = 0;
	array = (char *)s;
	while (i < n)
	{
		array[i] = (char)c;
		i++;
	}
	return (s);
}
