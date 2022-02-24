/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:10:07 by mbelorge          #+#    #+#             */
/*   Updated: 2020/07/02 23:04:23 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	search_number_sprite(t_sl *sl)
{
	int	x;
	int	y;

	x = 0;
	while (x < sl->map.lo)
	{
		y = 0;
		while (y < sl->map.la)
		{
			if (sl->map.tabmap[x][y] == 'C')
				sl->sprite_nb++;
			y++;
		}
		x++;
	}
}

void	init_texture(t_sl *sl)
{
	sl->play.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/perso1.xpm",
			&sl->play.width, &sl->play.height);
	sl->play.i.adrr = mlx_get_data_addr(sl->play.i.img,
			&sl->play.i.bpx, &sl->play.i.line_l, &sl->play.i.endian);
	sl->wal.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/wall.xpm", &sl->wal.width, &sl->wal.height);
	sl->wal.i.adrr = mlx_get_data_addr(sl->wal.i.img,
			&sl->wal.i.bpx, &sl->wal.i.line_l, &sl->wal.i.endian);
	sl->ex.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/doorclosed.xpm", &sl->ex.width, &sl->ex.height);
	sl->ex.i.adrr = mlx_get_data_addr(sl->ex.i.img,
			&sl->ex.i.bpx, &sl->ex.i.line_l, &sl->ex.i.endian);
	sl->col.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/burger.xpm", &sl->col.width, &sl->col.height);
	sl->col.i.adrr = mlx_get_data_addr(sl->col.i.img,
			&sl->col.i.bpx, &sl->col.i.line_l, &sl->col.i.endian);
	sl->enm.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/cochon.xpm", &sl->enm.width, &sl->enm.height);
	sl->enm.i.adrr = mlx_get_data_addr(sl->enm.i.img, &sl->enm.i.bpx,
			&sl->enm.i.line_l, &sl->enm.i.endian);
	sl->door.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/dooropen.xpm", &sl->door.width, &sl->door.height);
	sl->door.i.adrr = mlx_get_data_addr(sl->door.i.img,
			&sl->door.i.bpx, &sl->door.i.line_l, &sl->door.i.endian);
}

void	init_text_end(t_sl *sl)
{
	sl->dead.i.img = mlx_xpm_file_to_image(sl->mlx_ptr, "./images/dead2.xpm",
			&sl->dead.width, &sl->dead.height);
	sl->dead.i.adrr = mlx_get_data_addr(sl->dead.i.img,
			&sl->dead.i.bpx, &sl->dead.i.line_l, &sl->dead.i.endian);
	sl->wins.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/win2.xpm", &sl->wins.width, &sl->wins.height);
	sl->wins.i.adrr = mlx_get_data_addr(sl->wins.i.img,
			&sl->wins.i.bpx, &sl->wins.i.line_l, &sl->wins.i.endian);
	sl->over.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/gameover.xpm", &sl->over.width, &sl->over.height);
	sl->over.i.adrr = mlx_get_data_addr(sl->over.i.img,
			&sl->over.i.bpx, &sl->over.i.line_l, &sl->over.i.endian);
	sl->back.i.img = mlx_xpm_file_to_image(sl->mlx_ptr,
			"./images/back.xpm", &sl->back.width, &sl->back.height);
	sl->back.i.adrr = mlx_get_data_addr(sl->back.i.img,
			&sl->back.i.bpx, &sl->back.i.line_l, &sl->back.i.endian);
}

void	screen_end(t_sl *sl)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	sl->imend.img = mlx_new_image(sl->mlx_ptr, sl->resol.width / 3,
			sl->resol.heigth / 3);
	sl->imend.adrr = mlx_get_data_addr(sl->imend.img, &sl->imend.bpx,
			&sl->imend.line_l, &sl->imend.endian);
	if (sl->loose == 1 || sl->moove > 56)
		fill_sprt_data3(sl, i, j, &sl->over);
	else if (sl->point <= 0)
		fill_sprt_data3(sl, i, j, &sl->dead);
	else if (sl->win == 1)
		fill_sprt_data3(sl, i, j, &sl->wins);
}
