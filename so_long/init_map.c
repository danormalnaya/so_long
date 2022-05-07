/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:17:37 by lloko             #+#    #+#             */
/*   Updated: 2022/05/07 20:45:22 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_game(char *file, t_game *carta)
{
	carta->e_count = 0;
	carta->c_count = 0;
	carta->p_count = 0;
	carta->score = 0;
	carta->coll = 0;
	read_map(file, carta);
}
