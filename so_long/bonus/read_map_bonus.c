/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:24:45 by lloko             #+#    #+#             */
/*   Updated: 2022/05/15 19:15:16 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_rows(char *file, t_game *carta)
{
	int		fd;
	char	*temp;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		game_over ("File didn't read");
	str = get_next_line(fd);
	carta->map.y++;
	while (str)
	{
		temp = str;
		str = get_next_line(fd);
		free(temp);
		carta->map.y++;
	}
	close (fd);
}

static void	map_in_arr(int fd, t_game *carta)
{
	char	*str;
	int		i;

	carta->map.arr = malloc(sizeof(char *) * (carta->map.y + 1));
	if (!(carta->map.arr))
		game_over("Map didn't allocation\n");
	str = get_next_line(fd);
	if (!str)
		game_over("Map reading error\n");
	i = 0;
	while (str)
	{
		carta->map.arr[i] = str;
		carta->map.arr[i + 1] = NULL;
		str = get_next_line(fd);
		i++;
	}
}

void	read_map(char *file, t_game *carta)
{
	int		fd;

	count_rows(file, carta);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		game_over("Map didn't read");
	map_in_arr(fd, carta);
	if (map_check(carta->map.arr, file, carta) != 0)
	{
		free(carta->map.arr);
		game_over("The map contains an error\n");
	}
	close (fd);
}
