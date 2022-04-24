/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 19:24:45 by lloko             #+#    #+#             */
/*   Updated: 2022/04/24 19:32:57 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	check_map_ext(char *path, char *ber)
{
	char	*p;
	int		i;
	int		j;

	p = ft_strrchr(path, '.');
	if (!p)
		printf("Incorrect extension, must be '.ber'!");
	i = 0;
	while (p[i])
	{
		j = 0;
		if (p[i + j] == ber[j])
		{
			while (p[i + j] || ber[j])
			{
				if (p[i + j] != ber[j])
					printf("Incorrect extension, must be '.ber'!");
				j++;
			}
		}
		i++;
	}
}

static int	check_map_length(char *str, t_map *data)
{
	return ((int)ft_strlen(str) == data->col);
}

void	rows_in_map(char *path, t_map *data)
{
	char	*str;
	int		fd;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Map doesn't open!");
	str = get_next_line(fd);
	if (!str)
		printf("Map reading error");
	data->col = ft_strlen(str);
	data->row++;
	while (str)
	{
		tmp = str;
		str = get_next_line(fd);
		free(tmp);
		data->row++;
	}
	close(fd);
}

static int	is_valid(char c, t_map *data, int r, int col)
{
	if (c == 'P')
	{
		data->p_count++;
		data->player.i = col;
		data->player.j = r;
		return (1);
	}
	else if (c == 'C')
	{
		data->c_count++;
		return (1);
	}
	else if (c == 'E')
	{
		data->e_count++;
		return (1);
	}
	else if (c == '1' || c == '0')
		return (1);
	return (0);
}

int	validation_map(t_map *data)
{
	int		r;
	int		c;

	r = 0;
	while (data->arr[r])
	{
		if (!check_map_length(data->arr[r], data))
			return (0);
		c = 0;
		while (data->arr[r][c])
		{
			if (!is_valid(data->arr[r][c], data, r, c))
				return (0);
			if (r == 0 || (r == data->row - 1) || c == 0
				|| (c == data->col - 1))
				if (data->arr[r][c] != '1')
					return (0);
			c++;
		}
		r++;
	}
	if (data->p_count > 1 || data->c_count < 1 || data->e_count < 1)
		return (0);
	return (1);
}

void	read_map(char *path, t_map *data)
{
	int		fd;

	check_map_ext(path, ".ber");
	rows_in_map(path, data);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Map doesn't open");
	if (!validation_map(data))
	{
		//clean(data);
		printf("Map validation error");
	}
	close(fd);
}

int main(t_map *data, char **argv)
{
	(read_map(argv[1], &data));
	return (0);
}
