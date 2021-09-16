/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarihet <rarihet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:25:32 by rarihet           #+#    #+#             */
/*   Updated: 2020/01/17 04:05:29 by rarihet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int		check_color(char *colors)
{
	int			col;
	int			i;

	i = 0;
	while (colors[i] && !(colors[i] >= '0' && colors[i] <= '9'))
		i++;
	col = 65280 * ft_atoi(&colors[i]);
	i += how_long(ft_atoi(&colors[i]), 10);
	while (colors[i] && !(colors[i] >= '0' && colors[i] <= '9'))
		i++;
	col += 255 * ft_atoi(&colors[i]);
	i += how_long(ft_atoi(&colors[i]), 10);
	while (colors[i] && !(colors[i] >= '0' && colors[i] <= '9'))
		i++;
	col += ft_atoi(&colors[i]);
	return (col);
}

int		manage_colors(char *colors, int num, int i)
{
	int	vir;
	int nb_num;

	vir = 0;
	nb_num = 0;
	while (colors[i])
	{
		num = -1;
		while (colors[i] && (colors[i] >= '0' && colors[i] <= '9'))
		{
			num = ft_atoi(&colors[i]);
			i += how_long(num, 10);
		}
		if (num >= 0)
			nb_num++;
		if (num < 0 || num > 255)
			return (-1);
		if (colors[i] == ',')
			vir++;
		if (colors[i] != '\0')
			i++;
	}
	if (vir != 2 && nb_num != 3)
		return (-1);
	return (check_color(colors));
}

void	manage_tex_bonus(t_list *l)
{
	if (l->l_map->t_fl == 1)
	{
		l->tex[5].img = mlx_xpm_file_to_image(l->mlx, l->l_map->fl_tex, \
&l->tex[5].h, &l->tex[5].w);
		l->tex[5].data = mlx_get_data_addr(l->tex[5].img, &l->tex[5].bpp, \
&l->tex[5].sl, &l->tex[5].endian);
		free(l->l_map->fl_tex);
	}
	if (l->l_map->s1 == 1)
	{
		l->tex[6].img = mlx_xpm_file_to_image(l->mlx, l->l_map->s1_tex, \
&l->tex[6].h, &l->tex[6].w);
		l->tex[6].data = mlx_get_data_addr(l->tex[6].img, &l->tex[6].bpp, \
&l->tex[6].sl, &l->tex[6].endian);
		free(l->l_map->s1_tex);
	}
	if (l->l_map->s2 == 1)
	{
		l->tex[7].img = mlx_xpm_file_to_image(l->mlx, l->l_map->s2_tex, \
&l->tex[7].h, &l->tex[7].w);
		l->tex[7].data = mlx_get_data_addr(l->tex[7].img, &l->tex[7].bpp, \
&l->tex[7].sl, &l->tex[7].endian);
		free(l->l_map->s2_tex);
	}
}

void	manage_texture(t_list *l)
{
	l->tex[0].img = mlx_xpm_file_to_image(l->mlx, l->l_map->t_no, \
&l->tex[0].h, &l->tex[0].w);
	l->tex[0].data = mlx_get_data_addr(l->tex[0].img, &l->tex[0].bpp, \
&l->tex[0].sl, &l->tex[0].endian);
	l->tex[1].img = mlx_xpm_file_to_image(l->mlx, l->l_map->t_so, \
&l->tex[1].h, &l->tex[1].w);
	l->tex[1].data = mlx_get_data_addr(l->tex[1].img, &l->tex[1].bpp, \
&l->tex[1].sl, &l->tex[1].endian);
	l->tex[2].img = mlx_xpm_file_to_image(l->mlx, l->l_map->t_ea, \
&l->tex[2].h, &l->tex[2].w);
	l->tex[2].data = mlx_get_data_addr(l->tex[2].img, &l->tex[2].bpp, \
&l->tex[2].sl, &l->tex[2].endian);
	l->tex[3].img = mlx_xpm_file_to_image(l->mlx, l->l_map->t_we, \
&l->tex[3].h, &l->tex[3].w);
	l->tex[3].data = mlx_get_data_addr(l->tex[3].img, &l->tex[3].bpp, \
&l->tex[3].sl, &l->tex[3].endian);
	l->tex[4].img = mlx_xpm_file_to_image(l->mlx, l->l_map->s_tex, \
&l->tex[4].h, &l->tex[4].w);
	l->tex[4].data = mlx_get_data_addr(l->tex[4].img, &l->tex[4].bpp, \
&l->tex[4].sl, &l->tex[4].endian);
	manage_tex_bonus(l);
	free_l_map(l);
}
