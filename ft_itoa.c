/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:58:58 by dbank             #+#    #+#             */
/*   Updated: 2024/11/01 08:29:51 by dbank            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fillstring(int n, int negative, char *newstring, int position)
{
	if (negative == 1)
	{
		newstring[0] = '-';
		position++;
	}
	newstring[position] = '\0';
	position--;
	while ((position >= 0 && negative == 0) || (position >= 1 && negative == 1))
	{
		newstring[position] = n % 10 + '0';
		n /= 10;
		position--;
	}
	return (newstring);
}

static	size_t	calc_digits(int n)
{
	size_t	digits;

	digits = 1;
	while (n >= 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	char	*newstring;
	int		negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	else
		negative = 0;
	digits = calc_digits(n);
	newstring = malloc((digits + 1 + negative) * sizeof(char));
	if (newstring == NULL)
		return (NULL);
	return (fillstring(n, negative, newstring, digits));
}
