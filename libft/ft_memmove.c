/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:36:19 by abenzaho          #+#    #+#             */
/*   Updated: 2024/10/22 15:32:44 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*t1;
	unsigned const char	*t2;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	t1 = (unsigned char *)dst;
	t2 = (unsigned const char *)src;
	i = 0;
	if (t1 > t2)
	{
		while (n--)
			t1[n] = t2[n];
	}
	else
	{
		while (i < n)
		{
			t1[i] = t2[i];
			i++;
		}
	}
	return (dst);
}
