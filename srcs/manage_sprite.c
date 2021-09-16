/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:12:09 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 04:48:19 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_order(int nb_s, int spord[nb_s], double spdis[nb_s])
{
	double	max;
	int		i;
	int		j;

	i = 0;
	max = spdis[0];
	while (i < nb_s)
	{
		j = 0;
		while (j < nb_s - 1)
		{
			if (spdis[j] < spdis[j + 1])
			{
				ft_swap_double(&spdis[j], &spdis[j + 1]);
				ft_swap(&spord[j], &spord[j + 1]);
				i = 0;
			}
			j++;
		}
		i++;
	}
}

int		which_spite_is_it(t_list *l, int who)
{
	if (who == '2')
		return (4);
	else if (who == '3' && l->l_map->s1 == 1)
		return (6);
	else if (who == '4' && l->l_map->s2 == 1)
		return (7);
	return (4);
}

void	display_sprite(t_list *l, t_sprite sprite, int texx, int str)
{
	const int		w_sp = which_spite_is_it(l, sprite.whoiam);
	int				y;
	int				d;
	int				texy;

	while (++str < l->i_sp->drawendx)
	{
		texx = (int)(256 * (str - (-l->i_sp->sw / 2 + l->i_sp->spscx)) * \
l->tex[w_sp].w / l->i_sp->sw) / 256;
		if (l->i_sp->trfy > 0 && str > 0 && \
str < l->ray->resox && l->i_sp->trfy < l->zbuf[str])
		{
			y = l->i_sp->drawsty - 1;
			while (y < l->i_sp->drawendy && ++y)
			{
				d = y * 256 - l->ray->resoy * 128 + l->i_sp->sph * 128;
				texy = ((d * l->tex[w_sp].w) / l->i_sp->sph) / 256;
				l->color = texy % l->tex[w_sp].w * l->tex[w_sp].sl + \
texx % l->tex[w_sp].h * l->tex[w_sp].bpp / 8;
				if (l->tex[w_sp].data[l->color] != 0)
					ft_memcpy(&l->image_ptr[(l->ray->resox * y + str) * 4], \
&l->tex[w_sp].data[l->color], sizeof(int));
			}
		}
	}
}

void	cal_pos_sprite(t_list *l, int spord[l->nb_s], int i)
{
	const double	spx = l->sprites[spord[i]].posx - l->perso->posx;
	const double	spy = l->sprites[spord[i]].posy - l->perso->posy;
	double			inv;
	double			transfx;

	inv = 1.0 / (l->ray->px * l->ray->diry - l->ray->dirx * l->ray->py);
	transfx = inv * (l->ray->diry * spx - l->ray->dirx * spy);
	l->i_sp->trfy = inv * (-l->ray->py * spx + l->ray->px * spy);
	l->i_sp->spscx = (l->ray->resox / 2) * (1 + transfx / l->i_sp->trfy);
	l->i_sp->sph = abs((int)(l->ray->resoy / l->i_sp->trfy));
	l->i_sp->drawsty = -l->i_sp->sph / 2 + l->ray->resoy / 2;
	if (l->i_sp->drawsty < 0)
		l->i_sp->drawsty = 0;
	l->i_sp->drawendy = l->i_sp->sph / 2 + l->ray->resoy / 2;
	if (l->i_sp->drawsty >= l->ray->resoy)
		l->i_sp->drawsty = l->ray->resoy - 1;
	l->i_sp->sw = abs((int)(l->ray->resoy / l->i_sp->trfy));
	l->i_sp->drawstx = -l->i_sp->sw / 2 + l->i_sp->spscx;
	if (l->i_sp->drawstx < 0)
		l->i_sp->drawstx = 0;
	l->i_sp->drawendx = l->i_sp->sw / 2 + l->i_sp->spscx;
	if (l->i_sp->drawendx >= l->ray->resox)
		l->i_sp->drawendx = l->ray->resox - 1;
	display_sprite(l, l->sprites[spord[i]], 0, l->i_sp->drawstx - 1);
}

void	manage_sprite(t_list *l)
{
	int		i;
	int		spord[l->nb_s];
	double	spdis[l->nb_s];

	i = 0;
	while (i < l->nb_s)
	{
		spord[i] = i;
		spdis[i] = ((l->perso->posx - l->sprites[i].posx) * (l->perso->posx - \
l->sprites[i].posx) + (l->perso->posy - l->sprites[i].posy) * \
(l->perso->posy - l->sprites[i].posy));
		i++;
	}
	sort_order(l->nb_s, spord, spdis);
	i = 0;
	while (i < l->nb_s)
	{
		cal_pos_sprite(l, spord, i);
		i++;
	}
}
