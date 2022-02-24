/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	charactere_valide(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else
		return (0);
}

void	check_error_resolution(t_sl *sl)
{
	int		max_x;
	int		max_y;

	if (!sl->resol.width || !sl->resol.heigth)
		ft_error_fd(1, " ");
	sl->mlx_ptr = mlx_init();
	if (sl->resol.width < 100 || sl->resol.heigth < 100)
	{
		ft_putstr_fd("do not abuse the resolution please - resize 100 * 100\n",
			1);
		sl->resol.width = 100;
		sl->resol.heigth = 100;
	}
	mlx_get_screen_size(sl->mlx_ptr, &max_x, &max_y);
	if (sl->resol.width > max_x)
	{
		printf("%d -> too big - resize width automatic\n", sl->resol.width);
		sl->resol.width = max_x;
	}
	if (sl->resol.heigth > max_y)
	{
		printf("%d -> too big - resize heigth automatic\n", sl->resol.heigth);
		sl->resol.heigth = max_y;
	}
}

/*
** verfie que les bords de la map sont bien à 1
*/

void	check_error_border_map(char **map, t_map m)
{
	int		x;
	int		y;

	x = 0;
	while (x < m.lo)
	{
		y = 0;
		while (y < m.la)
		{
			if ((x == 0 || x == m.lo - 1 || y == m.la - 1 || y == 0)
				&& (map[x][y] != '1'))
				ft_error_map(1, ' ', x, y);
			y++;
		}
		x++;
	}
}

void	ft_error_nb_element(t_sl *sl)
{
	if (sl->cpt_p < 1)
		ft_error_fd(2, "player");
	if (sl->cpt_p > 1)
		ft_error_fd(3, "player");
	if (sl->cpt_e < 1)
		ft_error_fd(2, "exit");
	if (sl->cpt_e > 1)
		ft_error_fd(3, "exit");
	if (sl->cpt_c < 1)
		ft_error_fd(2, "objet");
}

/*
** verifie les erreurs dans la map
*/

void	check_error_inside_map(char **map, t_map m, t_sl *sl)
{
	int		x;
	int		y;

	x = 0;
	while (x < m.lo)
	{
		y = 0;
		while (y < m.la)
		{
			if (charactere_valide(map[x][y]) != 1)
				ft_error_map(4, map[x][y], x, y);
			if (map[x][y] == 'E')
				sl->cpt_e++;
			if (map[x][y] == 'C')
				sl->cpt_c++;
			if (map[x][y] == 'P')
				sl->cpt_p++;
			y++;
		}
		x++;
	}
	ft_error_nb_element(sl);
}
