/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:25 by abenzaho          #+#    #+#             */
/*   Updated: 2024/10/24 17:25:59 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (10);
	else if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa2(char *str, int n, int len)
{
	str[len] = '\0';
	len = len - 1;
	if (n >= 0)
		n = -n;
	while (len >= 0)
	{
		str[len] = -(n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = number_len(n);
	if (n < 0)
	{
		str = (char *)malloc(len + 2);
		len++;
	}
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str = ft_itoa2(str, n, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
