/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_double_tab(char **tab, int lenght)
{
	int	i;

	i = 0;
	while (i < lenght)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_texture(t_sl *sl)
{
	mlx_destroy_image(sl->mlx_ptr, sl->back.i.img);
	mlx_destroy_image(sl->mlx_ptr, sl->play.i.img);
	mlx_destroy_image(sl->mlx_ptr, sl->wal.i.img);
	mlx_destroy_image(sl->mlx_ptr, sl->ex.i.img);
	mlx_destroy_image(sl->mlx_ptr, sl->col.i.img);
	mlx_destroy_image(sl->mlx_ptr, sl->door.i.img);
}

void	free_all(t_sl *sl)
{
	free_texture(sl);
	free_double_tab(sl->map.tabmap, sl->map.lo);
	if (sl->mlx_ptr)
	{
		if (sl->win_ptr)
			mlx_destroy_window(sl->mlx_ptr, sl->win_ptr);
		mlx_destroy_display(sl->mlx_ptr);
		free(sl->mlx_ptr);
	}
}
