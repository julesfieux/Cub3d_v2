/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:16:49 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 05:14:58 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		manage_args(int ac, char **av)
{
	int		i;

	if (ac != 2 && ac != 3)
		return (ft_failure(NULL, "Il me faut au moins une map\n"));
	i = ft_strlen(av[1]);
	if (i < 3)
		return (1);
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u' || \
av[1][i - 3] != 'c' || av[1][i - 4] != '.')
		return (ft_failure(NULL, "La map n'est pas en .cub\n"));
	return (0);
}

void	check_line(t_list *l, char *map, int ord)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (!(map[i] >= '0' && map[i] <= '4') && \
map[i] != 'N' && map[i] != 'S' && map[i] != 'W' && map[i] != 'E')
			return ;
		i++;
	}
	if (i == 0 || ord < 8)
		return ;
	if (ft_strlen(l->l_map->map) % (i + 1) != 0)
	{
		l->l_map->fail = 1;
		return ;
	}
	l->l_map->map = ft_strjoin(l->l_map->map, map);
	l->l_map->map = ft_strjoin(l->l_map->map, "\n");
}

void	manage_other_line(t_list *l, char *map, int ord)
{
	if (map[0] == 'F' && map[1] == 'L' && \
map[2] == ' ' && map[3] == '.' && ++l->l_map->t_fl)
		l->l_map->fl_tex = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == '1' && \
map[2] == ' ' && map[3] == '.' && ++l->l_map->s1)
		l->l_map->s1_tex = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == '2' && \
map[2] == ' ' && map[3] == '.' && ++l->l_map->s2)
		l->l_map->s2_tex = ft_substr(map, 3, ft_strlen(map));
	else
		check_line(l, map, ord);
}

int		manage_each_line(t_list *l, char *map, int ord)
{
	if (map[0] == 'R' && map[1] == ' ' && ++ord)
		l->l_map->reso = ft_substr(map, 2, ft_strlen(map));
	else if (map[0] == 'N' && map[1] == 'O' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_no = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == 'O' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_so = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'W' && map[1] == 'E' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_we = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'E' && map[1] == 'A' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_ea = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == ' ' && ++l->nb_t && ++ord)
		l->l_map->s_tex = ft_substr(map, 2, ft_strlen(map));
	else if (map[0] == 'F' && map[1] == ' ' && ++ord)
		l->l_map->col_floor = ft_substr(map, 2, ft_strlen(map));
	else if (map[0] == 'C' && map[1] == ' ' && ++ord)
		l->l_map->col_ceil = ft_substr(map, 2, ft_strlen(map));
	else
		manage_other_line(l, map, ord);
	return (ord);
}

int		manage_map(t_list *l, char **av)
{
	char		*res;
	int			fd;
	int			ret;
	int			ord;

	res = NULL;
	ord = 0;
	if ((fd = open(av[1], O_RDONLY)) <= 0)
		return (ft_failure(l, "La map n existe pas\n"));
	while ((ret = get_next_line(fd, &res, 1024)) >= 0)
	{
		ord = manage_each_line(l, res, ord);
		free(res);
		res = NULL;
		if (l->l_map->fail == 1)
			return (ft_failure(l, "La map est mal faite\n"));
		if (ret == 0)
			break ;
	}
	if (ord != 8)
		return (ft_failure(l, "La map est mal faite, manque d instructions\n"));
	if (l->l_map->t_fl == 0 && l->l_map->s1 == 0 && l->l_map->s2 == 0)
		free(l->bonus);
	return (0);
}
