/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
** parcours la ligne envoyée et rempli la map,
** si la longueur est plus courte que la plus longue ligne, ajoute un espace
*/

void	fill_map(char **map, char *line, t_map m)
{
	m.y = 0;
	while (m.y < m.la && m.x <= m.lo)
	{
		map[m.x][m.y] = line[0];
		line++;
		m.y++;
	}
	map[m.x][m.y] = '\0';
}

void	check_map(char *ligne, t_sl *sl)
{
	if ((int)ft_strlen(ligne) != sl->map.la)
		ft_error_div(2);
	fill_map(sl->map.tabmap, ligne, sl->map);
	sl->map.x++;
}

void	ft_read_fd(int fd, t_sl *sl)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	sl->map.tabmap = malloc (sizeof(char *) * sl->map.lo + 1);
	while (i < sl->map.lo)
	{
		sl->map.tabmap[i] = (char *) malloc(sizeof(char) * sl->map.la + 1);
		i++;
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == '\0')
			break ;
		check_map(line, sl);
		free(line);
	}
	if (line[0] != '\0')
		check_map(line, sl);
	sl->map.tabmap[sl->map.lo] = NULL;
	check_error_border_map(sl->map.tabmap, sl->map);
	check_error_inside_map(sl->map.tabmap, sl->map, sl);
	free(line);
}
