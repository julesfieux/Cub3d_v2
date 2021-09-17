/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:33:14 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/17 18:35:51 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

/*char	**fill_end(char **r, int j, int k)
{
	if (j > 0)
	{
		r[k][j] = '\n';
		r[k][j + 1] = '\0';
	}
	else
		r[k] = NULL;
	r[k + 1] = NULL;
	return (r);
}*/

void	display_dead(t_list *l)
{
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 10, COL, \
"++***-----------------------------------------------------***************");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 9, COL, \
"+***||||||||-------|||||||||||+++||||||||||-****|||||||||||*+***|||||||***");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 8, COL, \
"++*||      ||-----||--+--+--+----||      ||****+||||********++**|||   ||***");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 7, COL, \
"+++||        ||---||||||||||---_-||||||||||**++++||||||||||++**|||    |||**");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 6, COL, \
"-++||      ||-----||--+--+--+----||      ||****+||||********+***|||   ||***");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 5, COL, \
"--*||||||||------_|||||||||||+++-||      ||+++++|||||||||||++***|||||||***");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 4, COL, \
"---+++**------------------------------------------------------***++****++++");
	mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy, COL, \
"----++++****************************************************+***++++***++*");
}

void	display_life(t_list *l, int i, char *heart)
{
	mlx_string_put(l->mlx, l->win, l->ray->resox - 70, 20, 0, "LEVEL :");
	if (i > 0)
		mlx_string_put(l->mlx, l->win, l->ray->resox / 4, 50, \
COL, heart);
	else
	{
		mlx_string_put(l->mlx, l->win, l->ray->resox / 4, l->ray->resoy / 2 - \
l->ray->resoy / 10 + 50, COL, \
"++*****************+***********************************************++++***");
		display_dead(l);
	}
}

void	cal_life(t_list *l, int life, int i, int nb)
{
	char	heart[104];
	char	level[2];

	while (i < life)
	{
		heart[i] = '|';
		i++;
	}
	nb = i;
	while (i < 100)
	{
		heart[i] = 'X';
		i++;
	}
	i = nb;
	heart[102] = nb % 10 + '0';
	nb = nb / 10;
	heart[101] = nb % 10 + '0';
	nb = nb / 10;
	heart[100] = nb % 10 + '0';
	heart[103] = '\0';
	level[0] = l->level + '0';
	level[1] = '\0';
	mlx_string_put(l->mlx, l->win, l->ray->resox - 50, 50, 0, level);
	display_life(l, i, heart);
}
