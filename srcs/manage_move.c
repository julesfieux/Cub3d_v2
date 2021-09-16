/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 00:23:15 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 04:02:24 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	manage_right(t_list *l, double mov, double posx, double posy)
{
	if (l->move_right == 1)
	{
		if (l->map_2d[(int)posx][(int)(posy + l->ray->py * mov)] == '0')
			l->perso->posy += l->ray->py * mov;
		if (l->map_2d[(int)(posx + l->ray->px * mov)][(int)posy] == '0')
			l->perso->posx += l->ray->px * mov;
	}
	else if (l->move_left == 1)
	{
		if (l->map_2d[(int)(posx - l->ray->px * mov)][(int)posy] == '0')
			l->perso->posx -= l->ray->px * mov;
		if (l->map_2d[(int)(posx)][(int)(posy - l->ray->py * mov)] == '0')
			l->perso->posy -= l->ray->py * mov;
	}
}

void	manage_move_no_ang(t_list *l, double mov, double posx, double posy)
{
	if (l->map_2d[(int)(posx - 0.5)][(int)(posy - 0.5)] == '3')
		l->life--;
	if (l->map_2d[(int)(posx - 0.5)][(int)(posy - 0.5)] == '2' && \
l->level < 9 && l->l_map->s1 == 1)
		l->level++;
	if (l->move_up == 1)
	{
		if (l->map_2d[(int)(posx + l->ray->dirx * mov)][(int)posy] == '0')
			l->perso->posx += l->ray->dirx * mov;
		if (l->map_2d[(int)posx][(int)(posy + l->ray->diry * mov)] == '0')
			l->perso->posy += l->ray->diry * mov;
	}
	else if (l->move_down == 1)
	{
		if (l->map_2d[(int)(posx - l->ray->dirx * mov)][(int)posy] == '0')
			l->perso->posx -= l->ray->dirx * mov;
		if (l->map_2d[(int)posx][(int)(posy - l->ray->diry * mov)] == '0')
			l->perso->posy -= l->ray->diry * mov;
	}
	manage_right(l, mov, posx, posy);
}

void	move_up_left(t_list *l)
{
	double			old_dirx;
	double			old_planex;
	const double	ro = l->perso->rots;

	if (l->move_ang_right == 1)
	{
		old_dirx = l->ray->dirx;
		l->ray->dirx = l->ray->dirx * cos(-ro) - l->ray->diry * sin(-ro);
		l->ray->diry = old_dirx * sin(-ro) + l->ray->diry * cos(-ro);
		old_planex = l->ray->px;
		l->ray->px = l->ray->px * cos(-ro) - l->ray->py * sin(-ro);
		l->ray->py = old_planex * sin(-ro) + l->ray->py * cos(-ro);
	}
	else if (l->move_ang_left == 1)
	{
		old_dirx = l->ray->dirx;
		l->ray->dirx = l->ray->dirx * cos(ro) - l->ray->diry * sin(ro);
		l->ray->diry = old_dirx * sin(ro) + l->ray->diry * cos(ro);
		old_planex = l->ray->px;
		l->ray->px = l->ray->px * cos(ro) - l->ray->py * sin(ro);
		l->ray->py = old_planex * sin(ro) + l->ray->py * cos(ro);
	}
	manage_move_no_ang(l, l->perso->ms, l->perso->posx, l->perso->posy);
}

int		manage_move(t_list *l)
{
	move_up_left(l);
	start_game(l);
	if (l->help == 1)
	{
		mlx_string_put(l->mlx, l->win, 10, 10,
				COL, "Press W A S D or the arrow keys to move.");
		mlx_string_put(l->mlx, l->win, 10, 30,
				COL, "Press H to show or hide this help.");
		mlx_string_put(l->mlx, l->win, 10, 50,
				COL, "Press ESC to quit.");
	}
	cal_life(l, l->life, 0, 0);
	return (0);
}
