/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:34:37 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/08 15:33:38 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_str(char *str, char **line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*line = ft_substr(str, 0, i);
			return (i);
		}
		i++;
	}
	return (-1);
}

int		manage_concl(char **line, char **str, int ret, int fd)
{
	char	*tmp;

	if (ret < 0)
		return (-1);
	if ((ret = check_str(str[fd], line)) > 0)
	{
		tmp = str[fd];
		str[fd] = ft_substr(str[fd], (ret + 1), \
(ft_strlen(str[fd]) - (ret + 1)));
		free(tmp);
		return (1);
	}
	*line = ft_strdup(str[fd]);
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

int		manage_sub(char **str, int fd, int ret)
{
	char *tmp;

	tmp = str[fd];
	str[fd] = ft_substr(str[fd], (ret + 1), (ft_strlen(str[fd]) - (ret + 1)));
	free(tmp);
	return (1);
}

int		get_next_line(int fd, char **line, int buff_size)
{
	static char	*str[1024];
	char		buff[buff_size + 1];
	int			ret;

	if (!line || fd < 0 || buff_size <= 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strdup("");
	if ((ret = check_str(str[fd], line)) >= 0)
		return (manage_sub(str, fd, ret));
	while ((ret = read(fd, buff, buff_size)) > 0)
	{
		buff[ret] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		ret = check_str(str[fd], line);
		if (ret >= 0)
			return (manage_sub(str, fd, ret));
	}
	return (manage_concl(line, str, ret, fd));
}
