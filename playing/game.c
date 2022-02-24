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

#include "../so_long.h"

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
