/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:12:31 by mbelorge          #+#    #+#             */
/*   Updated: 2020/05/02 19:09:31 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_struct_sl2(t_sl *sl)
{
	sl->resol.width = 900;
	sl->resol.heigth = 900;
	sl->play.i.adrr = NULL;
	sl->play.width = 0;
	sl->play.height = 0;
	sl->ext = NULL;
	sl->cpt_e = 0;
	sl->cpt_p = 0;
	sl->cpt_c = 0;
	sl->moove = 0;
}

void	init_struct_sl(t_sl *sl)
{
	sl->map.lo = 1;
	sl->map.la = 0;
	sl->map.x = 0;
	sl->map.y = 0;
	sl->map.tabmap = NULL;
	sl->sprite_nb = 0;
	sl->object = 0;
	sl->point = 5;
	sl->end = 0;
	sl->loose = 0;
	sl->win = 0;
	sl->map.tabmap = NULL;
	sl->player.x = 0;
	sl->player.y = 0;
	sl->move.av_rec = 0;
	sl->move.av = 0;
	sl->move.rec = 0;
	sl->move.left = 0;
	sl->move.right = 0;
	init_struct_sl2(sl);
}

void	check_arg(t_sl *sl, char **argv)
{
	if (ft_strlen(argv[1]) < 4)
		ft_error_div(6);
	sl->ext = ft_substr(argv[1], ft_strlen(argv[1]) - 4, ft_strlen(argv[1]));
	if (ft_strncmp(sl->ext, ".ber", 4) != 0)
		ft_error_div(6);
	free(sl->ext);
}

void	map_size(int fd, t_sl *sl)
{
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	sl->map.la = (int)ft_strlen(line);
	free(line);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == '\0')
			break ;
		sl->map.lo++;
		free(line);
		line = NULL;
	}
	if (line[0] != '\0')
		sl->map.lo++;
	free(line);
}

/*
**check_fd = check si il y a toutes les infos + reprend la taille de la map
** ft_read_fd = apel des parsing
*/

int	main(int argc, char **argv)
{
	int		fd;
	t_sl	sl;

	init_struct_sl(&sl);
	check_error_resolution(&sl);
	if (argc == 2)
	{
		check_arg(&sl, argv);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_error_div(1);
		map_size(fd, &sl);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		ft_read_fd(fd, &sl);
		close(fd);
		start_game(&sl);
	}
	else if (argc < 2)
		ft_error_div(4);
	else
		ft_error_div(3);
	return (EXIT_SUCCESS);
}
