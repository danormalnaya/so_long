/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:34:54 by lloko             #+#    #+#             */
/*   Updated: 2022/04/28 18:55:42 by lloko            ###   ########.fr       */
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

static int	valid_positions(char **map, t_game *carta)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				carta->e_count++;
			if (map[i][j] == 'P')
				carta->p_count++;
			if (map[i][j] == 'C')
				carta->c_count++;
			j++;
		}
		i++;
	}
	if (carta->e_count != 1 || carta->p_count != 1 || carta->c_count < 1)
	{
		write(1, "The map contains an error\n", 26);
		return (1);
	}
	return (0);
}

static int	valid_walls(char **map)
{
	int	i;
	int	j;
	int	col;
	int	row;

	col = ft_strlen(map[0]);
	row = 0;
	while (map[row])
		row++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				break;
			if (map[0][j] != '1' || map[row - 1][j] != '1'
				|| map[i][0] != '1' || map[i][col - 2] != '1')
				return (1);
			j++;
		}
		if (j != col - 1)
			return (1);
		i++;
	}
	return (0);
}

static int	valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				break;
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_extention_file(char *file)
{
	char	*name;

	if (!file)
		return (1);
	name = ft_strrchr(file, '.');
	if (ft_strncmp(name, ".ber", 4))
		return (1);
	return (0);
}

int	map_check(char **map, char *file)
{
	t_game	carta;

	carta.e_count = 0;
	carta.p_count = 0;
	carta.c_count = 0;
	//printf("1 - %d\n", valid_positions(map, &carta));
	printf("2 - %d\n", valid_walls(map));
	printf("3 - %d\n", valid_characters(map));
	printf("4 - %d\n", valid_extention_file(file));
	if (map)
		if (valid_positions(map, &carta) || valid_walls(map)
			|| valid_characters(map) || valid_extention_file(file))
			return (1);
	return (0);
}

int main(int fd, char **argv)
{
	char	*carta;
	char	**prov;
	t_game	*game;
	int		i = 0;

	fd = open(argv[1], O_RDONLY);
	carta = get_next_line(fd);
	prov = malloc(sizeof(char *) * 20);
	prov[i] = carta;
	while (carta)
	{
		printf("%s", carta);
		carta = get_next_line(fd);
		i++;
		prov[i] = carta;
	}
	printf("\n\n");
	if (map_check(prov, argv[1]))
		printf("fail");
	printf("\n\n");
	i = 0;
	while (prov[i])
	{
		printf("%s", prov[i]);
		i++;
	}
	return (0);
}
