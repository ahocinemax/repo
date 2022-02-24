/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_pixel(t_image *image, int x, int y, int argb)
{
	char			*result;

	result = image->adrr + (y * image->line_l + x * (image->bpx / 8));
	*(unsigned int *)result = argb;
}

unsigned int	my_mlx_pixel_get(t_image img, int x, int y)
{
	unsigned int	color;
	char			*ptr;

	ptr = img.adrr + (y * img.line_l + x * (img.bpx / 8));
	color = *(unsigned int *)ptr;
	return (color);
}

int	create_rgb(int r, int g, int b)
{
	unsigned int	color;

	color = r;
	color = (color << 8) + g;
	color = (color << 8) + b;
	return (color);
}

int	get_pixel_color(t_texture *text, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x > text->width)
		x = text->width;
	if (y > text->height)
		y = text->height;
	dst = text->i.adrr + (y * text->i.line_l + x * text->i.bpx / 8);
	return (*(unsigned int *)dst);
}
