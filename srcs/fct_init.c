/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:06:49 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/17 17:43:53 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	manage_start_n_s(char **map, int x, int y, t_list *l)
{
	if (map[y][x] == 'S')
	{
		l->ray->px = 0.0;
		l->ray->py = -0.66;
		l->ray->dirx = 1.0;
		l->ray->diry = 0;
	}
	else if (map[y][x] == 'N')
	{
		l->ray->dirx = -1.0;
		l->ray->diry = 0;
		l->ray->px = 0.0;
		l->ray->py = 0.66;
	}
}

void	manage_start_pos(char **map, int x, int y, t_list *l)
{
	manage_start_n_s(map, x, y, l);
	if (map[y][x] == 'W')
	{
		l->ray->px = 0.66;
		l->ray->py = 0.0;
		l->ray->dirx = 0.0;
		l->ray->diry = 1.0;
	}
	else if (map[y][x] == 'E')
	{
		l->ray->px = -0.66;
		l->ray->py = 0.0;
		l->ray->dirx = 0.0;
		l->ray->diry = -1.0;
	}
	l->perso->posx = y + .5;
	l->perso->posy = x + .5;
}

int		init_var_list(t_list *l)
{
	if ((l->l_map->map = ft_substrdup("", 0, 1)) == NULL)
		return (1);
	l->l_map->size_map = 0;
	l->l_map->fail = 0;
	l->l_map->t_fl = 0;
	l->l_map->s1 = 0;
	l->l_map->s2 = 0;
	l->l_map->nb_line = 0;
	l->nb_texture = 0;
	l->nb_s = 0;
	l->move_down = 0;
	l->move_left = 0;
	l->move_right = 0;
	l->move_ang_left = 0;
	l->move_ang_right = 0;
	l->move_up = 0;
	l->help = 1;
	l->life = 100;
	l->level = 1;
	return (0);
}

t_list	*init_list(void)
{
	t_list	*l;

	if ((l = malloc(sizeof(t_list))) == NULL)
		return (0);
	if ((l->perso = malloc(sizeof(t_perso))) == NULL)
		return (0);
	if ((l->ray = malloc(sizeof(t_move))) == NULL)
		return (0);
	if ((l->l_map = malloc(sizeof(t_init_map))) == NULL)
		return (0);
	if ((l->i_sp = malloc(sizeof(t_info_sprite))) == NULL)
		return (0);
	if ((l->bonus = malloc(sizeof(t_bonus))) == NULL)
		return (0);
	if (init_var_list(l) == 1)
		return (0);
	//l->play = ac - 2;
	return (l);
}
