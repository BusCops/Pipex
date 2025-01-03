/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:23:59 by abenzaho          #+#    #+#             */
/*   Updated: 2024/10/23 10:25:03 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;

	j = ft_strlen(src);
	if (!dst && size == 0)
		return (j);
	i = ft_strlen(dst);
	if (size <= i)
		return (j + size);
	if (j < size - i)
		ft_memcpy(dst + i, src, j + 1);
	else
	{
		ft_memcpy(dst + i, src, size - i - 1);
		dst[size - 1] = '\0';
	}
	return (i + j);
}
