/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:23:34 by lloko             #+#    #+#             */
/*   Updated: 2022/04/24 19:02:45 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	valid_positions(char **map, t_map *carta)
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
	if (carta->e_count != 1 || carta->p_count != 1 || carta->c_count == 0)
		return (1);
	return (0);
}

static int	valid_walls(char **str, t_map *carta)
{
	int	i;
	int	j;

	carta->col = ft_strlen(str[0]);
	carta->row = 0;
	while (str[carta->row])
		carta->row++;
	i = 0;
	while (carta->arr[i])
	{
		j = 0;
		while (carta->arr[i][j])
		{
			printf("%c", carta->arr[i][j]);
			if (i == 0 || (i == carta->row - 1) || j == 0
				|| (j == carta->col - 1))
				if (carta->arr[i][j] != '1')
					return (1);
			j++;
		}
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
		return (0);
	name = ft_strrchr(file, '.');
	if (ft_strncmp(name, ".ber", 4))
		return (1);
	return (0);
}

int	map_check(char **map, char *file)
{
	t_map	carta;

	carta.e_count = 0;
	carta.p_count = 0;
	carta.c_count = 0;
	printf("1 - %d\n", valid_positions(map, &carta));
	printf("2 - %d\n", valid_walls(map, &carta));
	printf("3 - %d\n", valid_characters(map));
	printf("4 - %d\n", valid_extention_file(file));
	if (map)
		if (valid_positions(map, &carta) || valid_walls(map, &carta)
			|| valid_characters(map) || valid_extention_file(file))
			return (1);
	return (0);
}

int main(int fd, char **argv)
{
	char	*carta;
	char 	**prov;
	int		i = 1;

	fd = open(argv[1], O_RDONLY);
	carta = get_next_line(fd);
	prov = malloc(sizeof(char *) * 7);
	prov[0] = carta;
	while (carta)
	{
		printf("%s", carta);
		carta = get_next_line(fd);
		prov[i] = carta;
		i++;
	}
	if (map_check(prov, argv[1]))
		printf("fail");
	return (0);
}
