/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:11:02 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/21 10:29:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destiny;
	const unsigned char	*source;

	i = 0;
	destiny = dst;
	source = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*duplicate;

	i = 0;
	duplicate = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (duplicate == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	concat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		concat[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		concat[i + j] = s2[j];
		j++;
	}
	concat[i + j] = '\0';
	return (concat);
}
