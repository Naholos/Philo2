/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoteo-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:11:56 by aoteo-be          #+#    #+#             */
/*   Updated: 2022/01/21 10:11:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

static size_t	first_word(const char *s, char c)
{
	size_t	counter;

	counter = 0;
	if (c != '\0')
	{
		while (s[counter] == c)
			counter = counter + 1;
	}
	return (counter);
}

static size_t	count_words(const char *s, char c, size_t *st)
{
	size_t	i;
	long	words;

	i = *st;
	words = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		words++;
		if (s[i] == '\0')
			break ;
		while (s[i] == c)
			i++;
	}
	return (words);
}

static size_t	sb(size_t *st, const char *s, char c)
{
	size_t	counter;

	counter = *st;
	while (s[counter] == c && s[counter] != '\0')
		counter++;
	*st = counter;
	while (s[counter] != c && s[counter] != '\0')
		counter++;
	return (counter - *st);
}

static char	**free_loop(long i, char **split)
{
	while (i >= 0)
	{
		free(*(split + i));
		i--;
	}
	free (split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**spl;
	size_t	st;
	long	words;
	long	i;

	if (s == NULL)
		return (NULL);
	st = first_word(s, c);
	words = (long)count_words(s, c, &st);
	spl = (char **)malloc((words + 1) * sizeof(char *));
	if (spl == NULL)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		*(spl + i) = (char *)malloc((sb(&st, (char *)s, c) + 1) * sizeof(char));
		if (*(spl + i) == NULL)
			return (free_loop(i - 1, spl));
		ft_memcpy((void *)*(spl + i), s + st, sb(&st, (char *)s, c));
		*(*(spl + i) + sb(&st, (char *)s, c)) = '\0';
		st += sb(&st, (char *)s, c);
	}
	*(spl + i) = NULL;
	return (spl);
}
