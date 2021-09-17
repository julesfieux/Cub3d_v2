/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:16:49 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/17 17:50:30 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		manage_args(int ac, char **av)
{
	int		i;

	if (ac != 2 && ac != 3)
		return (ft_failure(NULL, "Il me faut au moins une map\n"));
	i = ft_strlen(av[1]);
	if (i < 3)
		return (1);
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u' || \
av[1][i - 3] != 'c' || av[1][i - 4] != '.')
		return (ft_failure(NULL, "La map n'est pas en .cub\n"));
	return (0);
}

/*int		check_line(t_list *l, char *map, int ord)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (!(map[i] >= '0' && map[i] <= '4') && \
map[i] != 'N' && map[i] != 'S' && map[i] != 'W' && map[i] != 'E')
			return (0);
		i++;
	}
	if (ord < 8)
		return (0);
	if (ft_strlen(l->l_map->map) % (i + 1) != 0)
	{
		l->l_map->fail = 1;
		printf("elle est mal faite ici");
		return (0);
	}
	l->l_map->map = ft_strjoin(l->l_map->map, map);
	l->l_map->map = ft_strjoin(l->l_map->map, "\n");
	return (1);
}*/

/*int		manage_other_line(t_list *l, char *map, int ord)
{
	if (map[0] == 'F' && map[1] == 'L' && \
map[2] == ' ' && map[3] == '.' && ++l->l_map->t_fl)
		l->l_map->fl_tex = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == '1' && \
map[2] == ' ' && map[3] == '.' && ++l->l_map->s1)
		l->l_map->s1_tex = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == '2' && \
map[2] == ' ' && map[3] == '.' && ++l->l_map->s2)
		l->l_map->s2_tex = ft_substr(map, 3, ft_strlen(map));
	else
		if (!(check_line(l, map, ord)))
			return (0);
	return (1);
}*/

/*int		manage_each_line(t_list *l, char *map, int ord)
{
	if (map[0] == 'R' && map[1] == ' ' && ++ord)
		l->l_map->reso = ft_substr(map, 2, ft_strlen(map));
	else if (map[0] == 'N' && map[1] == 'O' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_no = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == 'O' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_so = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'W' && map[1] == 'E' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_we = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'E' && map[1] == 'A' && map[2] == ' ' && \
map[3] == '.' && ++l->nb_t && ++ord)
		l->l_map->t_ea = ft_substr(map, 3, ft_strlen(map));
	else if (map[0] == 'S' && map[1] == ' ' && ++l->nb_t && ++ord)
		l->l_map->s_tex = ft_substr(map, 2, ft_strlen(map));
	else if (map[0] == 'F' && map[1] == ' ' && ++ord)
		l->l_map->col_floor = ft_substr(map, 2, ft_strlen(map));
	else if (map[0] == 'C' && map[1] == ' ' && ++ord)
		l->l_map->col_ceil = ft_substr(map, 2, ft_strlen(map));
	else
		if (!(manage_other_line(l, map, ord)))
			return (0);
	return (ord);
}*/

/*int		manage_map(t_list *l, char **av)
{
	char		*res;
	int			fd;
	int			ret;
	int			ord;

	res = NULL;
	ord = 0;
	if ((fd = open(av[1], O_RDONLY)) <= 0)
		return (ft_failure(l, "La map n existe pas\n"));
	while ((ret = get_next_line(fd, &res, 1024)) >= 0)
	{
		if (!(ord = manage_each_line(l, res, ord)))
			return (ft_failure(l, "La map est mal faite\n"));
		free(res);
		res = NULL;
		if (l->l_map->fail == 1)
			return (ft_failure(l, "La map est mal faite\n"));
		if (ret == 0)
			break ;
	}
	if (ord != 8)
		return (ft_failure(l, "La map est mal faite, manque d instructions\n"));
	if (l->l_map->t_fl == 0 && l->l_map->s1 == 0 && l->l_map->s2 == 0)
		free(l->bonus);
	return (0);
}*/

char *ft_strjoin_map(char *s1, char *s2)
{
    int i;
    int j;
    int k;
    char *new;

    i = 0;
    j = 0;
    k = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    while (s1[i] != '\0')
        i++;
    while (s2[j] != '\0')
        j++;
    if (!(new = malloc(sizeof(char) * (i + j + 2))))
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i] != '\0')
        new[k++] = s1[i++];
    while (s2[j] != '\0')
        new[k++] = s2[j++];
    new[k] = '\n';
    k += 1;
    new[k] = '\0';
    free(s1);
    return (new);
}

int ft_check_map(char *line, t_list *info_game)
{
    int size;

    //                                                             REMPLIR ALL TEXT BEFORE MAP
    // if (info_game->info->tex_ea == NULL || )
    size = ft_strlen(line);
    if (size > info_game->l_map->size_map)
        info_game->l_map->size_map = size;
    // printf("taille de line = %d\n", info_game->max_size);
    info_game->l_map->map = ft_strjoin_map(info_game->l_map->map, line);
    if (!info_game->l_map->map)
        return (-1);
    info_game->l_map->nb_line++;
    // printf("MAP SUR UNE LIGNE = |%s|\n", info_game->map_inline);
    return (0);
}

int *fill_color(char *line)
{
    int i;
    int *color;
    int size_nb;

    i = 0;
    size_nb = 0;
    // printf("LINE DANS FILL = |%s|\n", line);
    if (!(color = malloc(sizeof(int) * 3)))
        return (NULL);
    while (line[i] != '\0' && !(line[i] >= '0' && line[i] <= '9'))
        i++;
    if (line[i] == '\0')
        return (NULL);
    // printf("1 = %c et %d\n", line[i], i);
    color[0] = ft_atoi_size(&line[i], &size_nb);
    if (!(color[0] >= 0 && color[0] <= 255))
        return (NULL);
    i += size_nb;
    while (line[i] != '\0' && !(line[i] >= '0' && line[i] <= '9'))
        i++;
    if (line[i] == '\0')
        return (NULL);
    // printf("2 = %c et %d\n", line[i], i);
    color[1] = ft_atoi_size(&line[i], &size_nb);
    // printf("COLOR QUI BUG : |%d|\n", color[1]);
    if (!(color[1] >= 0 && color[1] <= 255))
        return (NULL);
    // printf("deuxième couleur sol = |%d|\n", info_game->info->color_floor[1]);
    i += size_nb;
    while (line[i] != '\0' && !(line[i] >= '0' && line[i] <= '9'))
        i++;
    if (line[i] == '\0')
        return (NULL);
    // printf("2 = %c et %d\n", line[i], i);
    color[2] = ft_atoi_size(&line[i], &size_nb);
    if (!(color[2] >= 0 && color[0] <= 255))
        return (NULL);
    return (color);
}

int ft_check_color(char *line, t_list *info_game, int i, int let)
{
    int j;

    while (line[i] != '\0' && line[i] == ' ')
        i++;
    if (line[i] == '\0')
        return (-1);
    j = 0;
    while (line[i + j] != '\0' && line[i + j] != ' ')
        j++;
    if (let == 0)
    {
        if ((info_game->l_map->col_floor = fill_color(ft_substrdup(line, i, j))) == NULL)
            return (-1);
	    info_game->l_map->c_fl = 65280 * info_game->l_map->col_floor[0] + 255 * info_game->l_map->col_floor[1] + info_game->l_map->col_floor[2];
        /*for (int k = 0; k < 3; k++)
            printf("%d", info_game->l_map->col_floor[k]);
        printf("\n");*/
    }
    else if (let == 1)
    {
        if ((info_game->l_map->col_ceil = fill_color(ft_substrdup(line, i, j))) == NULL)
            return (-1);
	    info_game->l_map->c_ce = 65280 * info_game->l_map->col_ceil[0] + 255 * info_game->l_map->col_ceil[1] + info_game->l_map->col_ceil[2];
        /*for (int k = 0; k < 3; k++)
            printf("%d", info_game->l_map->col_ceil[k]);
        printf("\n");*/
        }
    i += j;
    while (line[i] != '\0')
    {
        if (line[i] != ' ')
            return (-1);
        i++;
    }
    return (0);
}

void fill_tex(t_list *info_game, char *line, int let)
{
    if (let == 0)
        info_game->l_map->t_no = line;
    else if (let == 1)
        info_game->l_map->t_so = line;
    else if (let == 2)
        info_game->l_map->t_we = line;
    else if (let == 3)
        info_game->l_map->t_ea = line;
    else if (let == 4)
        info_game->l_map->s_tex = line;
}

int ft_check_tex(char *line, t_list *info_game, int let, int i)
{
    int j;

    while (line[i] != '\0' && line[i] == ' ')
        i++;
    if (line[i] == '\0')
        return (-1);
    j = 0;
    while (line[i + j] != '\0' && line[i + j] != ' ')
        j++;
    fill_tex(info_game, ft_substrdup(line, i, j), let);
    i += j;
    while (line[i] != '\0')
    {
        if (line[i] != ' ')
            return (-1);
        i++;
    }
    info_game->nb_texture = info_game->nb_texture + 1;
    return (0);
}

int ft_check_resolution(char *line, t_list *info_game)
{
    int i;
    int size_nb;

    i = 0;
    // printf("Line recue pour R = [%s]\n", line);
    while (line[i] != '\0' && !(line[i] >= '0' && line[i] <= '9'))
        i++;
    if (line[i] == '\0')
        return (-1);
    // printf("1 = %c et %d\n", line[i], i);
    info_game->ray->resox = ft_atoi_size(&line[i], &size_nb);
    i += size_nb;
    while (line[i] != '\0' && !(line[i] >= '0' && line[i] <= '9'))
        i++;
    if (line[i] == '\0')
        return (-1);
    // printf("2 = %c et %d\n", line[i], i);
    info_game->ray->resoy = ft_atoi_size(&line[i], &size_nb);
    i += size_nb;
    while (line[i] != '\0')
    {
        if (line[i] != ' ')
            return (-1);
        i++;
    }
    // printf("x = %d\ny = %d\n", info_game->r_x, info_game->r_y);
    return (0);
}

int check_line(char *line, int i, t_list *info_game)
{
    if (line[i] == 'R' && line[i + 1] == ' ')
    {
        if (ft_check_resolution(line, info_game) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
    {
        if (ft_check_tex(line, info_game, 0, i + 2) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
    {
        if (ft_check_tex(line, info_game, 1, i + 2) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
    {
        if (ft_check_tex(line, info_game, 2, i + 2) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
    {
        if (ft_check_tex(line, info_game, 3, i + 2) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'S' && line[i + 1] == ' ')
    {
        if (ft_check_tex(line, info_game, 4, i + 1) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'F' && line[i + 1] == ' ')
    {
        if (ft_check_color(line, info_game, i + 1, 0) != 0)
            return (-1);
        return (2);
    }
    else if (line[i] == 'C' && line[i + 1] == ' ')
    {
        if (ft_check_color(line, info_game, i + 1, 1) != 0)
            return (-1);
        return (2);
    }
    return (1);
}

int ft_parsing(char *line, t_list *info_game)
{
    int i;
    int ret;

    i = 0;
    ret = 1;
    while (line[i] != '\0')
    {

        if ((ret = check_line(line, i, info_game)) == -1)
            return (-1);
        if (line[i] == '1')
        {
            ret = 2;
            if (ft_check_map(line, info_game) != 0)
                return (-1);
        }
        if (ret != 1)
            break;
        i++;
    }
    return (0);
}

int ft_read_map(int ret, char *line, int fd, t_list *info_game)
{
    info_game->l_map->map = malloc(sizeof(char) * 1);
    while ((ret = get_next_line(&line, fd, 1024)) == 1)
    {
        if (ft_strlen(line) > 0)
            if (ft_parsing(line, info_game) != 0)
                return (-1);
    }
    if (check_char_map(info_game->info->map_inline, info_game) != 0)
        return (-1);
    printf("Tex NO = |%s|\n", info_game->info->tex_no);
    printf("Tex SO = |%s|\n", info_game->info->tex_so);
    printf("Tex EA = |%s|\n", info_game->info->tex_ea);
    printf("Tex WE = |%s|\n", info_game->info->tex_we);
    printf("Tex SPRITE = |%s|\n", info_game->info->tex_spr);
    printf("Color sol = |%d,%d,%d|\n", info_game->info->color_floor[0], info_game->info->color_floor[1], info_game->info->color_floor[2]);
    printf("Color plafond = |%d,%d,%d|\n", info_game->info->color_sky[0], info_game->info->color_sky[1], info_game->info->color_sky[2]);
    printf("MAP SUR UNE LIGNE = |%s|\n", info_game->info->map_inline);
    printf("Longeur de la plus grande ligne = |%d|\n", info_game->info->max_size);
    printf("Nombre de ligne de la map = |%d|\n", info_game->info->nb_line);
    if (ft_fill_tab(info_game) != 0)
    {
        printf("Fill tab FAIL\n");
        return (-1);
    }
    if ((fill_sprite_info(info_game, info_game->map_2d, 0)) == 1)
		return (1);
	printf("Fill tab ok\n");
    if (check_border_map(info_game->map_2d, info_game->info->nb_line) != 0)
    {
        printf("Check border FAIL\n");
        return (-1);
    }
	printf("JUSQUE LA TOUT EST OK\n");
	info_game->Zbuf = malloc(sizeof(double) * info_game->ray->resoX);
	info_game->perso->moveSpeed = 0.1;
	info_game->perso->rotSpeed = 0.05;
	printf("TOUUUUUUTTTTT OK\n");
    return (0);
}

int ft_open_map(char *str, t_list *info_game)
{
    char *line;
    int ret;
    int fd;

    ret = 1;
    line = NULL;
    if ((fd = open(str, O_RDONLY)) == -1)
        return (-1);
    if (ft_read_map(ret, line, fd, info_game) != 0)
        return (84);
    return (0);
}
