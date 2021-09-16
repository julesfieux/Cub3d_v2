/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 19:07:39 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 04:57:28 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(void)
{
	exit(0);
	return (0);
}

void	key_free(t_list *l)
{
	if (l->l_map->t_fl == 1)
		free(l->bonus);
	free(l->l_map);
	free(l->perso);
	free(l->ray);
	free(l->zbuf);
	free(l);
	exit(1);
}

int		key_press(int keycode, t_list *l)
{
	if (keycode == 4)
	{
		if (l->help == 1)
			l->help = 0;
		else
			l->help = 1;
	}
	if (keycode == 13 || keycode == 126)
		l->move_up = 1;
	else if (keycode == 1 || keycode == 125)
		l->move_down = 1;
	if (keycode == 124)
		l->move_ang_right = 1;
	else if (keycode == 123)
		l->move_ang_left = 1;
	if (keycode == 2)
		l->move_right = 1;
	else if (keycode == 0)
		l->move_left = 1;
	if (keycode == 53 || l->life <= 0)
		key_free(l);
	return (0);
}

int		key_release(int keycode, t_list *l)
{
	if (keycode == 13 || keycode == 126)
		l->move_up = 0;
	else if (keycode == 1 || keycode == 125)
		l->move_down = 0;
	if (keycode == 124)
		l->move_ang_right = 0;
	else if (keycode == 123)
		l->move_ang_left = 0;
	if (keycode == 2)
		l->move_right = 0;
	else if (keycode == 0)
		l->move_left = 0;
	return (0);
}
