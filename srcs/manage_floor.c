/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:14:48 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 04:06:34 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	manage_fill_tex_floor(t_list *l, int y)
{
	int	x;
	int cellx;
	int celly;
	int tx;
	int ty;

	x = 0;
	while (x < l->ray->resox)
	{
		cellx = (int)(l->bonus->floorx);
		celly = (int)(l->bonus->floory);
		tx = (int)(l->tex[5].w * (l->bonus->floorx - cellx));
		ty = (int)(l->tex[5].h * (l->bonus->floory - celly));
		tx = abs(tx);
		ty = abs(ty);
		l->bonus->floorx += l->bonus->flstepx;
		l->bonus->floory += l->bonus->flstepy;
		l->color = ty % l->tex[5].w * l->tex[5].sl + tx % l->tex[5].h * \
l->tex[5].bpp / 8;
		ft_memcpy(&l->image_ptr[(l->ray->resox * y + x) * 4], \
&l->tex[5].data[l->color], sizeof(int));
		x++;
	}
}

void	manage_floor(t_list *l, int y, int p, double posz)
{
	double	rowdist;
	double	raydirx0;
	double	raydirx1;
	double	raydiry0;
	double	raydiry1;

	while (y < l->ray->resoy)
	{
		raydirx0 = l->ray->dirx - l->ray->px;
		raydiry0 = l->ray->diry - l->ray->py;
		raydirx1 = l->ray->dirx + l->ray->px;
		raydiry1 = l->ray->diry + l->ray->py;
		p = abs(y - l->ray->resoy / 2);
		posz = 0.5 * l->ray->resoy;
		rowdist = posz / p;
		l->bonus->flstepx = rowdist * (raydirx1 - raydirx0) / l->ray->resox;
		l->bonus->flstepy = rowdist * (raydiry1 - raydiry0) / l->ray->resox;
		l->bonus->floorx = l->perso->posx + rowdist * raydirx0;
		l->bonus->floory = l->perso->posy + rowdist * raydiry0;
		manage_fill_tex_floor(l, y);
		y++;
	}
}
