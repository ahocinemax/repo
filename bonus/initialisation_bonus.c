/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2019/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_play_game(t_sl *sl)
{
	if (sl->win == 0 && sl->loose == 0 && sl->point > 0 && sl->moove <= 56)
	{
		put_element(sl);
		black_screen(sl);
		ft_up_and_down(sl);
		ft_left_right(sl);
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr,
			sl->img.img, 0, 0);
		point_number(sl);
		mlx_destroy_image(sl->mlx_ptr, sl->img.img);
	}
	else
	{	
		screen_end(sl);
		mlx_put_image_to_window(sl->mlx_ptr, sl->win_ptr, sl->imend.img,
			(sl->resol.width / 2) - (sl->iend.case_w / 2),
			(sl->resol.heigth / 2) - (sl->iend.case_h / 2));
		mlx_destroy_image(sl->mlx_ptr, sl->imend.img);
	}
	return (0);
}

void	init_draw(t_sl *sl)
{
	sl->iend.case_w = sl->resol.width / 3;
	sl->iend.case_h = sl->resol.heigth / 3;
	sl->el.case_w = sl->resol.width / sl->map.la;
	sl->el.case_h = sl->resol.heigth / sl->map.lo;
}

void	start_game(t_sl *sl)
{
	sl->win_ptr = mlx_new_window(sl->mlx_ptr, sl->resol.width,
			sl->resol.heigth, "so_long");
	search_player(sl);
	search_number_sprite(sl);
	init_draw(sl);
	init_texture(sl);
	init_text_end(sl);
	mlx_hook(sl->win_ptr, 2, 1L << 0, key_control, sl);
	mlx_hook(sl->win_ptr, 3, 1L << 1, key_control2, sl);
	mlx_loop_hook(sl->mlx_ptr, ft_play_game, sl);
	mlx_hook(sl->win_ptr, 33, 1L, close_cross, sl);
	mlx_loop(sl->mlx_ptr);
}
