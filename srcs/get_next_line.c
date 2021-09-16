/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:44:24 by jfieux            #+#    #+#             */
/*   Updated: 2021/01/28 18:16:36 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_new_line(char *str)
{
	int		i;
	char	*res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_new_save(char *str)
{
	int		i;
	int		j;
	char	*res;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	if (!(res = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1))))
		return (0);
	i++;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

int		ft_mall_save(char **save)
{
	if (!*save)
	{
		if ((*save = malloc(sizeof(char) * 1)) == NULL)
			return (-1);
		*save[0] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line, int	buff_size)
{
	int			ret;
	char		buf[buff_size + 1];
	static char	*save;

	ret = 1;
	if (fd < 0 || !line || buff_size < 1)
		return (-1);
	if (ft_mall_save(&save) < 0)
		return (-1);
	while (ft_found_return(save) == 0 && ret != 0)
	{
		if ((ret = read(fd, buf, buff_size)) == -1)
		{
			free(save);
			return (-1);
		}
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
	}
	*line = ft_new_line(save);
	save = ft_new_save(save);
	if (ret == 0)
		return (0);
	return (1);
}
