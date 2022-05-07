/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:33:28 by lloko             #+#    #+#             */
/*   Updated: 2022/05/05 15:32:53 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*map_in_arr(int fd, t_game *carta)
{
	char	*str;
	int		i;

	carta->map.arr = malloc(sizeof(char *) * (carta->map.x + 1));
	if (!(carta->map.arr))
		game_over("Map don't allocation\n");
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
	return(str);
}

void	read_map(char *file, t_game *carta)
{
	int	fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		game_over("Map don't read");
	map_in_arr(fd, carta);
	if (map_check != 0)
	{
		free(carta);
		game_over("Map unvalid");
	}
	close (fd);
}
