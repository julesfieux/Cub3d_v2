/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:34:48 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/10 18:31:03 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*r;

	i = 0;
	while (s[i])
		i++;
	if ((r = malloc(sizeof(char) * (i + 2))) == 0)		// pk un "+2" et pas un "+1"
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

char	*ft_strchr(char *s, int c)
{
	int i;

	if (c == '\0')
	{
		i = 0;
		while (s[i])
			i++;
		return ((char *)s + i);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			break ;
		s = s + 1;
	}
	if (*s == '\0')
		return (NULL);
	return ((char *)s);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen(s))
	{
		if ((r = malloc(sizeof(char) * 1)) == 0)
			return (NULL);
	}
	else
	{
		if ((r = malloc(sizeof(char) * (len + 1))) == 0)
			return (NULL);
		while (i < len && s[start + i] != '\0')
		{
			r[i] = s[start + i];
			i++;
		}
	}
	r[i] = '\0';
	return (r);
}

int		ft_strlen(char *s)
{
	int i;

	if (s == NULL || !s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((r = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))) == 0)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		r[i + j] = s2[j];
		j++;
	}
	free(s1);
	r[i + j] = '\0';
	return (r);
}
