/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:39:34 by abenzaho          #+#    #+#             */
/*   Updated: 2024/11/17 09:48:16 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*t1;
	unsigned const char	*t2;

	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	t2 = (unsigned const char *)src;
	t1 = (unsigned char *)dst;
	while (n > 0)
	{
		*t1 = *t2;
		t1++;
		t2++;
		n--;
	}
	return (dst);
}
