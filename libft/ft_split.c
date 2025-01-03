/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:03:08 by abenzaho          #+#    #+#             */
/*   Updated: 2024/10/26 17:33:00 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(const char *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (s[0] != c && s[0] != '\0')
		w++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			w++;
		i++;
	}
	return (w);
}

static char	*ft_cpy(int *start, int end, const char *s, char c)
{
	char	*str;

	while (s[*start] == c && s[*start])
		*start = *start + 1;
	str = (char *)malloc(end - *start + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s + *start, end - *start);
	str[end - *start] = '\0';
	if (s[end])
		*start = end + 1;
	else
		*start = end;
	while (s[*start] == c && s[*start])
		*start = *start + 1;
	return (str);
}

static void	ft_free(char **str, int words)
{
	int	i;

	i = 0;
	while (i < words)
		free(str[i++]);
	free(str);
}

static int	check_end(const char *s, int i, char c)
{
	int	k;

	k = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		k++;
	}
	if (k > 0)
		return (i);
	else
		return (-i - 5);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i++])
	{
		if (check_end(s, i - 1, c) >= 0)
		{
			str[j] = ft_cpy(&i, check_end(s, --i, c), s, c);
			if (!str[j++])
			{
				ft_free(str, j);
				return (NULL);
			}
		}
	}
	str[j] = NULL;
	return (str);
}
