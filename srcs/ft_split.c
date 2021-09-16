/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:20 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/13 19:35:24 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (cdest);
}

static char	**malloc_line_ft_split(char const *s, char c, char **r)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && j > 0 && s[i] != ' ')
		{
			if ((r[k] = malloc(sizeof(char) * (j + 3))) == 0)
				return (NULL);
			j = 0;
			k++;
		}
		else if (s[i] != c && s[i] != ' ')
			j++;
		i++;
	}
	if ((r[k] = malloc(sizeof(char) * (j + 3))) == 0)
		return (NULL);
	return (r);
}

static char	**malloc_ft_split(char const *s, char c, int i, int k)
{
	char	**r;

	while (s[i])
	{
		if (s[i] == c)
			k++;
		i++;
	}
	if ((r = malloc(sizeof(char *) * (k + 3))) == 0)
	{
		free(r);
		return (NULL);
	}
	if ((r = malloc_line_ft_split(s, c, r)) == NULL)
	{
		free(r);
		return (NULL);
	}
	return (r);
}

static char	**fill_ft_split(char const *s, char c, char **r, int i)
{
	int		k;
	int		j;

	k = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c && j > 0)
		{
			r[k][j] = '\n';
			r[k][j + 1] = '\0';
			j = 0;
			k++;
		}
		else if (s[i] != c && s[i] != ' ')
			r[k][j++] = s[i];
		i++;
	}
	return (fill_end(r, j, k));
}

char		**ft_split(char const *s, char c)
{
	char	**r;

	if (s == NULL)
		return (NULL);
	if ((r = malloc_ft_split(s, c, 0, 0)) == NULL)
		return (NULL);
	r = fill_ft_split(s, c, r, 0);
	return (r);
}
