/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// cherche le ratio entre la taille et la taille des cases de la map

void	draw_pix(t_sl *sl, t_texture *text, int back)
{
	int	x;
	int	k;
	int	color;
	int	y;

	x = -1;
	while (sl->d.pos_x + x < 0)
		x++;
	while (++x <= sl->el.case_w)
	{
		sl->d.text_x = x * (text->width / sl->el.case_w);
		y = sl->d.top_px - 1;
		k = -1;
		while (++y < sl->d.bot_px)
		{
			++k;
			sl->d.text_y = (k * (text->height / sl->el.case_h));
			if (sl->d.text_y < 0)
				sl->d.text_y = 0;
			color = get_pixel_color(text, sl->d.text_x, sl->d.text_y);
			if (color != back)
				image_pixel(&sl->img, sl->d.pos_x + x, y, color);
		}
	}
}

void	draw_pix2(t_sl *sl, t_texture *text)
{
	int	x;
	int	k;
	int	color;
	int	y;

	x = -1;
	while (sl->d.pos_x + x < 0)
		x++;
	while (++x <= sl->el.case_w)
	{
		sl->d.text_x = x * (text->width / sl->el.case_w);
		y = sl->d.top_px - 1;
		k = -1;
		while (++y < sl->d.bot_px)
		{
			++k;
			sl->d.text_y = (k * (text->height / sl->el.case_h));
			if (sl->d.text_y < 0)
				sl->d.text_y = 0;
			color = get_pixel_color(text, sl->d.text_x, sl->d.text_y);
			image_pixel(&sl->img, sl->d.pos_x + x, y, color);
		}
	}
}

void	draw_pix3(t_sl *sl, t_texture *text)
{
	int	x;
	int	k;
	int	color;
	int	y;

	x = -1;
	while (sl->d.pos_x + x < 0)
		x++;
	while (++x <= sl->iend.case_w)
	{
		sl->d.text_x = x * (text->width / sl->iend.case_w);
		y = sl->d.top_px - 1;
		k = -1;
		while (++y < sl->d.bot_px)
		{
			++k;
			sl->d.text_y = (k * (text->height / sl->iend.case_h));
			if (sl->d.text_y < 0)
				sl->d.text_y = 0;
			color = get_pixel_color(text, sl->d.text_x, sl->d.text_y);
			image_pixel(&sl->imend, sl->d.pos_x + x, y, color);
		}
	}
}

void	init_img(t_sl *sl)
{
	sl->img.img = mlx_new_image(sl->mlx_ptr, sl->resol.width, sl->resol.heigth);
	sl->img.adrr = mlx_get_data_addr(sl->img.img, &sl->img.bpx,
			&sl->img.line_l, &sl->img.endian);
}

void	put_element(t_sl *sl)
{
	int	i;
	int	j;

	i = -1;
	init_img(sl);
	while (++i < sl->map.lo)
	{
		j = 0;
		while (j < sl->map.la)
		{
			if (sl->map.tabmap[i][j] != '1')
				fill_sprt_data2(sl, i, j, &sl->back);
			if (sl->map.tabmap[i][j] == 'P')
				fill_sprt_data(sl, i, j, &sl->play);
			if (sl->map.tabmap[i][j] == 'E')
				fill_sprt_data(sl, i, j, &sl->ex);
			if (sl->map.tabmap[i][j] == 'C')
				fill_sprt_data(sl, i, j, &sl->col);
			if (sl->map.tabmap[i][j] == '1')
				fill_sprt_data(sl, i, j, &sl->wal);
			j++;
		}
	}
}
