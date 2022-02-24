/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	black_screen(t_sl *sl)
{
	int	yy;
	int	y;
	int	i;
	int	j;
	int	x;

	yy = sl->resol.width - 100 - 2;
	i = 0;
	x = 20;
	while (i < 40)
	{
		j = 0;
		y = yy;
		while (j < 100)
		{
			image_pixel(&sl->img, y, x, create_rgb(0, 0, 0));
			j++;
			y++;
		}
		i++;
		x++;
	}
}

void	point_number(t_sl *sl)
{
	char	*st;
	int		vt;
	char	*st2;
	char	*st4;
	char	*st3;

	st2 = ft_itoa(sl->moove);
	st4 = ft_itoa(sl->point);
	st = "PV  : ";
	st3 = "PDD : ";
	vt = create_rgb(0, 128, 0);
	sl->cl = create_rgb(0, 128, 0);
	sl->cl2 = create_rgb(0, 128, 0);
	if (sl->moove > 45)
		sl->cl = create_rgb(128, 0, 0);
	if (sl->point <= 2)
		sl->cl2 = create_rgb(128, 0, 0);
	mlx_string_put(sl->mlx_ptr, sl->win_ptr, sl->resol.width - 90, 35, vt, st3);
	mlx_string_put(sl->mlx_ptr, sl->win_ptr, sl->resol.width - 50, 35,
		sl->cl, st2);
	mlx_string_put(sl->mlx_ptr, sl->win_ptr, sl->resol.width - 90, 50, vt, st);
	mlx_string_put(sl->mlx_ptr, sl->win_ptr, sl->resol.width - 50, 50, sl->cl2,
		st4);
	free(st2);
	free(st4);
}

void	check_is_finish(t_sl *sl)
{
	if (sl->sprite_nb > 0)
	{
		ft_putstr_fd(""RED"GAME OVER\n"SET"", 1);
		sl->loose = 1;
	}
	else
	{
		ft_putstr_fd(""GREEN"YOU WIN !!!!\n"SET"", 1);
		sl->win = 1;
	}
}

void	playing_rules(t_sl *sl, int i, int j)
{
	if (sl->map.tabmap[sl->player.i][sl->player.j] == 'E')
	{
		fill_sprt_data2(sl, i, j, &sl->back);
		fill_sprt_data(sl, sl->player.i, sl->player.j, &sl->door);
		check_is_finish(sl);
	}
	else if (sl->map.tabmap[sl->player.i][sl->player.j] == 'C')
		sl->sprite_nb = sl->sprite_nb - 1;
}

void	search_player(t_sl *sl)
{
	int	x;
	int	y;
	int	compt;

	compt = 0;
	x = -1;
	while (++x < sl->map.lo)
	{
		y = -1;
		while (++y < sl->map.la)
		{
			if (sl->map.tabmap[x][y] == 'P')
			{
				sl->player.x = x;
				sl->player.y = y;
				sl->player.i = x;
				sl->player.j = y;
				compt++;
			}
			if (compt > 1)
				ft_error_map(7, ' ', 0, 0);
		}
	}
}
