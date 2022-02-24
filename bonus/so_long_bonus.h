/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:53:29 by mbelorge          #+#    #+#             */
/*   Updated: 2020/02/10 17:17:24 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"

# define ECHAP		65307
# define KEY_W		119
# define KEY_S		115
# define KEY_A		97
# define KEY_D		100
# define RED        "\033[31;01m" 
# define GREEN      "\033[32;01m"
# define SET 		"\033[00m"

typedef struct s_map
{
	int			lo;
	int			la;
	int			x;
	int			y;
	char		**tabmap;

}				t_map;

typedef struct s_resol
{
	int			width;
	int			heigth;

}				t_resol;

typedef struct s_image
{
	void		*img;
	char		*adrr;
	int			bpx;
	int			line_l;
	int			endian;

}				t_image;

typedef struct s_move
{
	int			av_rec;
	int			av;
	int			rec;
	int			left;
	int			right;
	int			cam;

}				t_move;

typedef struct s_param
{
	void		*mlx_ptr;
	void		*win_ptr;

}				t_param;

typedef struct s_player
{
	double		x;
	double		y;
	int			i;
	int			j;
}				t_player;

typedef struct s_color
{
	char		orientation;
	int			r;
	int			g;
	int			b;
	int			color_hex;

}				t_color;

typedef struct s_sprt
{
	float	case_h;
	float	case_w;
	float	right_px;

}				t_sprt;

typedef struct s_texture
{
	int			width;
	int			height;
	t_image		i;
}				t_texture;

typedef struct s_draw
{
	float	top_px;
	float	bot_px;
	float	pos_x;
	float	text_x;
	float	text_y;

}				t_draw;

typedef struct s_sl
{
	t_resol		resol;
	int			sprite_nb;
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	col;
	t_texture	enm;
	t_texture	play;
	t_texture	wal;
	t_texture	att;
	t_texture	ex;
	t_texture	back;
	t_texture	door;
	t_map		map;
	t_param		param;
	t_player	player;
	t_image		img;
	t_image		exit;
	double		speed_moove;
	double		olddir_x;
	double		olddir_y;
	double		oldplan_x;
	double		oldplan_y;
	int			moove;
	double		rotate;
	t_texture	wins;
	t_texture	over;
	t_texture	dead;
	t_image		imend;
	char		*sprite_path;
	t_move		move;
	char		*ext;
	int			object;
	int			point;
	int			end;
	int			loose;
	int			win;
	t_sprt		iend;
	t_sprt		el;
	t_draw		d;
	int			cpt_e;
	int			cpt_p;
	int			cpt_c;
	int			cl;
	int			cl2;
}				t_sl;

t_map			check_fd (int fd);
void			ft_read_fd(int fd, t_sl *sl);
void			check_map(char *line, t_sl *sl);
void			fill_map(char **map, char *line, t_map m);
void			check_error_border_map (char **map, t_map m);
void			check_error_inside_map (char **map, t_map m, t_sl *sl);
void			ft_error_map(int index, char a, int b, int c);
void			check_error_resolution(t_sl *sl);
void			ft_error_fd(int index, char *s);
void			ft_error_color_fd(int index, char c);
void			ft_error_div(int index);
void			start_game(t_sl *sl);
int				key_control(int key, t_sl *sl);
int				key_control2(int key, t_sl *sl);
void			ft_left_right(t_sl *sl);
int				create_rgb(int r, int g, int b);
void			image_pixel(t_image *image, int x, int y, int argb);
void			ft_up_and_down (t_sl *sl);
void			free_double_tab(char **tab, int lenght);
void			free_all(t_sl *sl);
void			search_number_sprite(t_sl *sl);
void			check_arg(t_sl *sl, char **argv);
void			put_element(t_sl *sl);
void			playing_rules(t_sl *cub, int i, int j);
void			check_is_finish(t_sl *cub);
void			fill_sprt_data(t_sl *sl, int i, int j, t_texture *text);
int				get_pixel_color(t_texture *text, int x, int y);
void			screen_end(t_sl *sl);
void			point_number(t_sl *cub);
void			black_screen(t_sl *sl);
void			init_texture(t_sl *sl);
int				close_cross(t_sl *sl);
void			search_player(t_sl *sl);
void			fill_sprt_data2(t_sl *sl, int i, int j, t_texture *text);
void			fill_sprt_data3(t_sl *sl, int i, int j, t_texture *text);
void			init_text_end(t_sl *sl);
void			fill_sprt_data3(t_sl *sl, int i, int j, t_texture *text);
void			check_is_finish(t_sl *sl);
void			playing_rules(t_sl *sl, int i, int j);
void			draw_pix(t_sl *sl, t_texture *text, int background);
void			draw_pix2(t_sl *sl, t_texture *text);
void			draw_pix3(t_sl *sl, t_texture *text);

#endif
