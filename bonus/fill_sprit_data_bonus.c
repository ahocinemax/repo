/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprite_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fill_sprt_data(t_sl *sl, int i, int j, t_texture *text)
{
	int		background;

	sl->d.top_px = i * sl->el.case_h;
	sl->d.bot_px = (i + 1) * sl->el.case_h;
	sl->d.pos_x = j * sl->el.case_w;
	background = get_pixel_color(text, 0, 0);
	draw_pix(sl, text, background);
}

void	fill_sprt_data2(t_sl *sl, int i, int j, t_texture *text)
{
	sl->d.top_px = i * sl->el.case_h;
	sl->d.bot_px = (i + 1) * sl->el.case_h;
	sl->d.pos_x = j * sl->el.case_w;
	draw_pix2(sl, text);
}

void	fill_sprt_data3(t_sl *sl, int i, int j, t_texture *text)
{
	sl->d.top_px = i * sl->iend.case_h;
	sl->d.bot_px = (i + 1) * sl->iend.case_h;
	sl->d.pos_x = j * sl->iend.case_w;
	draw_pix3(sl, text);
}
