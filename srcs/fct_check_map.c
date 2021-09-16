/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_check_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:19:47 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/16 14:09:19 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		manage_line(t_list *l, char *reso, char *c_fl, char *c_ce)
{
	int		i;

	i = 0;
	l->ray->resox = 0;
	l->ray->resoy = 0;
	while (reso[i] && !(reso[i] >= '0' && reso[i] <= '9'))
		i++;
	if (reso[i])
	{
		l->ray->resox = ft_atoi(&reso[i]);
		i += how_long(l->ray->resox, 10);
	}
	while (reso[i] && !(reso[i] >= '0' && reso[i] <= '9'))
		i++;
	if (reso[i])
		l->ray->resoy = ft_atoi(&reso[i]);
	if (l->ray->resox <= 0 || l->ray->resox > 2560 || \
l->ray->resoy <= 0 || l->ray->resoy > 1440)
		return (1);
	l->l_map->c_fl = manage_colors(c_fl, 0, 0);
	l->l_map->c_ce = manage_colors(c_ce, 0, 0);
	if (l->l_map->c_ce < 0 || l->l_map->c_fl < 0)
		return (1);
	return (0);
}

int		check_around(char **map, int y_max, int x_max)
{
	int i;

	i = 0;
	while (i < x_max)
	{
		if (map[0][i] != '1')
			return (1);
		if (map[y_max][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < y_max)
	{
		if (map[y_max][i] != '1')
			return (1);
		if (map[0][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int		check_map(t_list *l, char **map, int player)
{
	int		y;
	int		x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] >= '2' && map[y][x] <= '4')
				l->nb_s++;
			if (map[y][x] == 'N' || map[y][x] == 'S' || \
map[y][x] == 'W' || map[y][x] == 'E')
			{
				manage_start_pos(map, x, y, l);
				map[y][x] = '0';
				player++;
			}
			x++;
		}
		y++;
	}
	if (check_around(map, y - 1, x - 1) != 0)
		return (0);
	return (player);
}

int		fill_info_mp(t_list *l)
{
	char	**map;

	map = ft_split(l->l_map->map, '\n');
	free(l->l_map->map);
	l->perso->posx = 0;
	l->perso->posy = 0;
	if (check_map(l, map, 0) != 1)
		return (1);
	if (manage_line(l, l->l_map->reso, l->l_map->col_floor, \
l->l_map->col_ceil) == 1)
		return (1);
	if ((fill_sprite_info(l, map, 0)) == 1)
		return (1);
	l->zbuf = malloc(sizeof(double) * l->ray->resox);
	l->map_2d = map;
	l->perso->ms = 0.1;
	l->perso->rots = 0.05;
	return (0);
}

void	free_l_map(t_list *l)
{
	free(l->l_map->col_ceil);
	free(l->l_map->col_floor);
	free(l->l_map->t_we);
	free(l->l_map->t_ea);
	free(l->l_map->t_no);
	free(l->l_map->t_so);
	free(l->l_map->s_tex);
	free(l->l_map->reso);
}
