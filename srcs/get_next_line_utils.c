/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:44:51 by jfieux            #+#    #+#             */
/*   Updated: 2021/09/17 13:12:43 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

int		ft_found_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*char	*ft_substr(char *s, unsigned int start, size_t len)
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
}*/

char *ft_substrdup(char *str, int start, int size)
{
    char *s;
    int i;

    s = malloc(sizeof(char) * (size + 1));
    if (!s)
        return (NULL);
    i = 0;
    while (str[i] != '\0' && i < size)
    {
        s[i] = str[start + i];
        i++;
    }
    s[i] = '\0';
    return (s);
}
