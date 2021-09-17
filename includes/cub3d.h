/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfieux <jfieux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:34:51 by rarihet           #+#    #+#             */
/*   Updated: 2021/09/17 17:43:15 by jfieux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# include <stdio.h>

# define WINX 1024
# define WINY 720
# define COL 0xEEEEEE

typedef struct		s_init_map
{
	char			*map;
	int				size_map;
	char			*reso;
	char			*t_no;
	char			*t_so;
	char			*t_we;
	char			*t_ea;
	char			*s_tex;
	int				*col_floor;
	int				c_fl;
	int				*col_ceil;
	int				c_ce;
	int				t_fl;
	char			*fl_tex;
	int				s1;
	char			*s1_tex;
	int				s2;
	char			*s2_tex;
	int				nb_line;
	int				fail;
}					t_init_map;

typedef struct		s_move
{
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	int				mapx;
	int				mapy;
	double			hit;
	double			pwd;
	int				side;
	double			dirx;
	double			diry;
	double			px;
	double			py;
	int				resox;
	int				resoy;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			rayposx;
	double			rayposy;
	int				lineh;
	int				draws;
	int				drawe;
	int				bpp;
	int				sl;
	int				endian;
}					t_move;

typedef struct		s_text
{
	char			*img;
	char			*data;
	int				bpp;
	int				sl;
	int				h;
	int				w;
	int				endian;
}					t_text;

typedef struct		s_perso
{
	double			posx;
	double			posy;
	double			ms;
	double			rots;
}					t_perso;

typedef struct		s_sprite
{
	double			posx;
	double			posy;
	int				whoiam;
}					t_sprite;

typedef struct		s_bonus
{
	double			floorx;
	double			floory;
	double			flstepx;
	double			flstepy;
}					t_bonus;

typedef struct		s_info_sprite
{
	int				drawstx;
	int				drawendx;
	double			trfy;
	int				sw;
	int				spscx;
	int				sph;
	int				drawsty;
	int				drawendy;
}					t_info_sprite;

typedef struct		s_list
{
	t_init_map		*l_map;
	t_move			*ray;
	t_perso			*perso;
	t_sprite		*sprites;
	t_info_sprite	*i_sp;
	t_bonus			*bonus;
	t_text			tex[9];
	void			*mlx;
	void			*win;
	void			*image;
	char			*image_ptr;
	int				move_up;
	int				move_left;
	int				move_ang_left;
	int				move_ang_right;
	int				move_right;
	int				move_down;
	double			*zbuf;
	char			**map_2d;
	int				color;
	//int				nb_t;		parse
	int				nb_texture;
	int				nb_s;
	int				help;
	int				life;
	int				level;
	//int				play;		//-save
}					t_list;

int					manage_move(t_list *l);
int					start_game(t_list *l);
t_list				*init_list(void);
void				init_wall_var(t_list *l, int x);
void				manage_hit_wall(t_list *l);
void				manage_dir_wall(t_list *l);
void				calc_wall_size(t_list *l);
void				manage_sprite(t_list *l);
void				manage_floor(t_list *l, int y, int p, double posz);
void				dislay_wall_tex(t_list *l, double wallx, int start, int x);
//int					manage_each_line(t_list *l, char *map, int order);		//parse
//int					manage_map(t_list *l, char **av);		//parse
int 				ft_open_map(char *str, t_list *info_game);
int					fill_info_mp(t_list *l);
int					fill_sprite_info(t_list *l, char **map, int i);
void				manage_start_pos(char **map, int x, int y, t_list *l);
void				free_l_map(t_list *l);
void				manage_texture(t_list *l);
int					manage_colors(char *colors, int res, int i);
void				cal_life(t_list *l, int life, int i, int nb);
//int					create_bmp(t_list *l);		// -save
//int					create_screenshot(t_list *l);		// -save
void				key_free(t_list *l);
int					manage_args(int ac, char **av);

void				ft_swap(int *n1, int *n2);
void				ft_swap_double(double *n1, double *n2);
int					ft_failure(t_list *l, char *msg);
int					how_long(int nb, int size);
int					ft_atoi_size(const char *str, int *size);


//char				*ft_strdup(char *s);		//parse
char				*ft_substrdup(char *str, int start, int size);
char				*ft_strjoin(char *s1, char *s2);
//char				*ft_substr(char *s, unsigned int start, size_t len);		//parse
int					ft_found_return(char *str);
//char				*ft_strchr(char *s, int c);		//gnl
int					ft_strlen(char *s);
int					get_next_line(int fd, char **line, int buff_size);
void				ft_putstr(char *str);
char				**fill_end(char **r, int j, int k);
int					ft_strcmp(char *s1, char *s2);

int					manage_move(t_list *l);
int					ft_close(void);
int					key_press(int keycode, t_list *l);
int					key_release(int keycode, t_list *l);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
void				*ft_memcpy(void *dest, const void *src, size_t n);

#endif
