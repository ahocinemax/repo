/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	player_stop(t_sl *sl, int x, int y)
{
	if ((sl->map.tabmap[x][y] == '1') ||
			(sl->map.tabmap[x][y] == '2'))
		return (0);
	else
		return (1);
}

void	moove(t_sl *sl, int x, int y, char *temp)
{
	int	a;
	int	b;

	a = sl->player.i;
	b = sl->player.j;
	sl->moove++;
	temp = ft_itoa(sl->moove);
	ft_putstr_fd(temp, 1);
	ft_putstr_fd("\n", 1);
	sl->map.tabmap[sl->player.i][sl->player.j] = '0';
	sl->player.i = x;
	sl->player.j = y;
	if (sl->map.tabmap[x][y] == 'E' || sl->map.tabmap[x][y] == 'C')
		playing_rules(sl, a, b);
	sl->map.tabmap[x][y] = 'P';
	free(temp);
}

void	ft_up_and_down(t_sl *sl)
{
	int		tmpx;
	int		tmpy;
	char	*temp;

	temp = NULL;
	tmpx = sl->player.i;
	tmpy = sl->player.j;
	if (sl->move.av != 0)
	{
		if (!player_stop(sl, sl->player.i - 1, sl->player.j))
			sl->player.i = tmpx;
		else
			moove(sl, tmpx - 1, tmpy, temp);
	}
	if (sl->move.rec != 0)
	{
		if (!player_stop(sl, sl->player.i + 1, sl->player.j))
			sl->player.i = tmpx;
		else
			moove(sl, tmpx + 1, tmpy, temp);
	}
	if (sl->moove > 56 && (sl->move.rec != 0 || sl->move.av != 0))
		printf(""RED"GAME OVER - TOO MUCH MOVE\n"SET"");
	sl->move.av = 0;
	sl->move.rec = 0;
}

void	ft_left_right(t_sl *sl)
{
	int		tmpx;
	int		tmpy;
	char	*temp;

	temp = NULL;
	tmpx = sl->player.i;
	tmpy = sl->player.j;
	if (sl->move.left == 1)
	{
		if (!player_stop(sl, sl->player.i, sl->player.j - 1))
			sl->player.j = tmpy;
		else
			moove(sl, tmpx, tmpy - 1, temp);
	}
	if (sl->move.right == 1)
	{
		if (!player_stop(sl, sl->player.i, sl->player.j + 1))
			sl->player.j = tmpy;
		else
			moove(sl, tmpx, tmpy + 1, temp);
	}
	if (sl->moove > 56 && (sl->move.left == 1 || sl->move.right == 1))
		printf(""RED"GAME OVER - TOO MUCH MOVE\n"SET"");
	sl->move.right = 0;
	sl->move.left = 0;
}
