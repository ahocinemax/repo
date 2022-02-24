/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/08/03 18:45:10 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error_fd(int index, char *s)
{
	printf("Error\n");
	if (index == 1)
		printf("incorrect resolution ou no entry\n");
	if (index == 2)
		printf("no element for : %s", s);
	if (index == 3)
		printf("so much element for : %s", s);
	exit(EXIT_FAILURE);
}

void	ft_error_map(int index, char a, int b, int c)
{
	printf("Error\n");
	if (index == 1)
		printf("wall around map undefined, position : %d, %d or jump \n",
			b, c);
	else if (index == 2)
		printf("map's wall West undefined, line : %d\n", b + 1);
	else if (index == 3)
		printf("map's east undefined, line : %d\n", b + 1);
	else if (index == 4)
		printf("invalid map element %c, line : %d, row :  %d\n",
			a, b + 1, c);
	else if (index == 5)
		printf("no wall around position %d, %d\n", b, c);
	else if (index == 7)
		printf("multiple position player");
	exit(EXIT_FAILURE);
}

void	ft_error_div(int index)
{
	printf("Error\n");
	if (index == 1)
		printf("read error or no map\n");
	if (index == 2)
		printf("invadid map - please enter a rectangle map\n");
	if (index == 3)
		printf("error argument, enter one map only\n");
	if (index == 4)
		printf("please enter valid map\n");
	if (index == 6)
		printf("format map invalid - enter .ber extension for map/n");
	if (index == 8)
		printf("error new image no create\n");
	exit(EXIT_FAILURE);
}

void	ft_error_texture(int index, char *s)
{
	printf("Error\n");
	if (index == 1)
		printf("unloaded texture %s or error path\n", s);
	if (index == 2)
		printf("%s is not a correct texture\n", s);
	if (index == 3)
		printf("too much element for %s\n", s);
	exit(EXIT_FAILURE);
}
