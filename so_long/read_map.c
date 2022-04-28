/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:33:28 by lloko             #+#    #+#             */
/*   Updated: 2022/04/28 17:34:14 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static char	*form_map_arr(int fd, t_game *carta)
{
	char	*str;
	int		i;

	carta->map.arr = malloc(sizeof(char *) * (carta->map.x + 1));
	if (!(carta->map.arr))
		printf("Map allocation error");
	str = get_next_line(fd);
	if (!str)
		printf("Map reading error");
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

int main(int fd, char **argv)
{
	t_game *carta;
	char *str;
	
	fd = open(argv[1], O_RDONLY);
	printf("%d", fd);
	str = form_map_arr(fd, carta);
	return (0);
}