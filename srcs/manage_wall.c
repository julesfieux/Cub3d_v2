/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:09:45 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 04:42:24 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dislay_wall_tex(t_list *l, double wallx, int st, int x)
{
	int texy;
	int	texx;

	if ((l->ray->side == 0 || l->ray->side == 1))
		wallx = l->perso->posy + l->ray->pwd * l->ray->raydiry;
	else
		wallx = l->perso->posx + l->ray->pwd * l->ray->raydirx;
	wallx -= floor((wallx));
	texx = abs((int)(wallx * (double)64));
	st = l->ray->draws;
	while (st < l->ray->drawe)
	{
		texy = abs(((st * 2 - l->ray->resoy + l->ray->lineh) * 64) / \
(l->ray->lineh * 2));
		l->color = texy % l->tex[l->ray->side].w * l->tex[l->ray->side].sl + \
texx % l->tex[l->ray->side].h * l->tex[l->ray->side].bpp / 8;
		ft_memcpy(&l->image_ptr[(l->ray->resox * st + x) * 4], \
&l->tex[l->ray->side].data[l->color], sizeof(int));
		st++;
	}
}

void	init_wall_var(t_list *l, int x)
{
	l->ray->camerax = 2 * x / (double)l->ray->resox - 1.0;
	l->ray->rayposx = l->perso->posx;
	l->ray->rayposy = l->perso->posy;
	l->ray->raydirx = l->ray->dirx + l->ray->px * l->ray->camerax;
	l->ray->raydiry = l->ray->diry + l->ray->py * l->ray->camerax;
	l->ray->mapx = (int)l->ray->rayposx;
	l->ray->mapy = (int)l->ray->rayposy;
	l->ray->hit = 0;
	l->ray->deltadistx = sqrt(1 + (l->ray->raydiry * l->ray->raydiry) / \
(l->ray->raydirx * l->ray->raydirx));
	l->ray->deltadisty = sqrt(1 + (l->ray->raydirx * l->ray->raydirx) / \
(l->ray->raydiry * l->ray->raydiry));
}

void	manage_hit_wall(t_list *l)
{
	while (l->ray->hit == 0)
	{
		if (l->ray->sidedistx < l->ray->sidedisty)
		{
			l->ray->sidedistx += l->ray->deltadistx;
			l->ray->mapx += l->ray->stepx;
			if (l->ray->stepx > 0)
				l->ray->side = 0;
			else
				l->ray->side = 1;
		}
		else
		{
			l->ray->sidedisty += l->ray->deltadisty;
			l->ray->mapy += l->ray->stepy;
			if (l->ray->stepy > 0)
				l->ray->side = 2;
			else
				l->ray->side = 3;
		}
		if (l->map_2d[l->ray->mapx][l->ray->mapy] == '1')
			l->ray->hit = 1;
	}
}

void	manage_dir_wall(t_list *l)
{
	if (l->ray->raydirx < 0)
	{
		l->ray->stepx = -1;
		l->ray->sidedistx = (l->ray->rayposx - l->ray->mapx) * \
l->ray->deltadistx;
	}
	else
	{
		l->ray->stepx = 1;
		l->ray->sidedistx = (l->ray->mapx + 1.0 - l->ray->rayposx) * \
l->ray->deltadistx;
	}
	if (l->ray->raydiry < 0)
	{
		l->ray->stepy = -1;
		l->ray->sidedisty = (l->ray->rayposy - l->ray->mapy) * \
l->ray->deltadisty;
	}
	else
	{
		l->ray->stepy = 1;
		l->ray->sidedisty = (l->ray->mapy + 1.0 - l->ray->rayposy) * \
l->ray->deltadisty;
	}
}

void	calc_wall_size(t_list *l)
{
	if (l->ray->side <= 1)
		l->ray->pwd = (l->ray->mapx - l->ray->rayposx + \
(1 - l->ray->stepx) / 2) / l->ray->raydirx;
	else
		l->ray->pwd = (l->ray->mapy - l->ray->rayposy + \
(1 - l->ray->stepy) / 2) / l->ray->raydiry;
	l->ray->lineh = (int)(l->ray->resoy / l->ray->pwd);
	l->ray->draws = -l->ray->lineh / 2 + l->ray->resoy / 2;
	if (l->ray->draws < 0)
		l->ray->draws = 0;
	l->ray->drawe = l->ray->lineh / 2 + l->ray->resoy / 2;
	if (l->ray->drawe >= l->ray->resoy)
		l->ray->drawe = l->ray->resoy - 1;
}
