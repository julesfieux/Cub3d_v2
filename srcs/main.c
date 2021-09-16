/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:33:22 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/16 14:09:10 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int		fill_sprite_info(t_list *l, char **map, int i)
{
	int			x;
	int			y;
	t_sprite	*sp;

	if ((sp = malloc(sizeof(t_sprite) * (l->nb_s + 1))) == NULL)
		return (1);
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] >= '2' && map[y][x] <= '4')
			{
				sp[i].posx = y + 0.5;
				sp[i].posy = x + 0.5;
				sp[i].whoiam = map[y][x];
				i++;
			}
			x++;
		}
		y++;
	}
	l->sprites = sp;
	return (0);
}

void	manage_display(t_list *l, int x)
{
	int start;
	int	cal;

	start = 0;
	while (start < l->ray->draws)
	{
		l->image_ptr[(l->ray->sl * start) + (x * 4)] = l->l_map->c_ce;
		l->image_ptr[(l->ray->sl * start) + (x * 4) + 1] = l->l_map->c_ce >> 8;
		l->image_ptr[(l->ray->sl * start) + (x * 4) + 2] = l->l_map->c_ce >> 16;
		start++;
	}
	if (l->l_map->t_fl == 0)
	{
		start = l->ray->drawe;
		while (start < l->ray->resoy)
		{
			cal = (l->ray->sl * start) + (x * 4);
			l->image_ptr[cal] = l->l_map->c_fl;
			l->image_ptr[cal + 1] = l->l_map->c_fl >> 8;
			l->image_ptr[cal + 2] = l->l_map->c_fl >> 16;
			start++;
		}
	}
	dislay_wall_tex(l, 0, 0, x);
	l->zbuf[x] = l->ray->pwd;
}

int		start_game(t_list *l)
{
	int x;

	l->image = mlx_new_image(l->mlx, l->ray->resox, l->ray->resoy);
	l->image_ptr = mlx_get_data_addr(l->image, &l->ray->bpp, \
&l->ray->sl, &l->ray->endian);
	if (l->l_map->t_fl == 1)
		manage_floor(l, l->ray->resoy / 2 + 10, 0, 0);
	x = 0;
	while (x < l->ray->resox)
	{
		init_wall_var(l, x);
		manage_dir_wall(l);
		manage_hit_wall(l);
		calc_wall_size(l);
		manage_display(l, x);
		x++;
	}
	manage_sprite(l);
	mlx_put_image_to_window(l->mlx, l->win, l->image, 0, 0);
	/*if (l->play == 0)
		mlx_destroy_image(l->mlx, l->image);*/		//  -save
	return (0);
}

void	play_hook(t_list *l)
{
	mlx_hook(l->win, 17, 0L, ft_close, l);
	mlx_loop_hook(l->mlx, manage_move, l);
	mlx_hook(l->win, 2, 1L, key_press, l);
	mlx_key_hook(l->win, key_release, l);
	mlx_loop(l->mlx);
}

int		main(int ac, char **av)
{
	t_list		*l;

	if (manage_args(ac, av) == 1)
		return (0);
	if ((l = init_list()) == 0)
		return (ft_failure(NULL, "Malloc probleme"));
	/*manage_map(l, av);
	if (l->nb_t < 5)
		return (ft_failure(l, "Il manque des textures\n"));
	if (fill_info_mp(l) == 1)
		return (ft_failure(l, "La map est mal faites\n"));*/
	if (ft_open_map(av[1], l) != 0)
		return (ft_failure(l, "la map est mal faite"));
	//printf("nbT = %d\n", nbT);
	if (nbT < 5)
		return (ft_failure(l, "le jeu a besoin de toute les textures ou aucune"));
	if (((l->mlx = mlx_init()) == NULL))
		return (ft_failure(l, "Probleme de minilibX\n"));
	if (!(l->win = mlx_new_window(l->mlx, l->ray->resox, \
l->ray->resoy, "cube3d")))
		return (ft_failure(l, "La fenetre ne s ouvre pas\n"));
	manage_texture(l);
	/*if (l->play == 1)
		return (create_screenshot(l));		// -save
	else*/
	play_hook(l);
	return (0);
}
