/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:04:03 by abenzaho          #+#    #+#             */
/*   Updated: 2024/10/22 11:12:17 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t i)
{
	unsigned char	*t;

	t = (unsigned char *)str;
	while (i > 0)
	{
		*t = (unsigned char)c;
		i--;
		t++;
	}
	return (str);
}
