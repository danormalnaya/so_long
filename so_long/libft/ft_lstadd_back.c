/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:55:44 by lloko             #+#    #+#             */
/*   Updated: 2022/01/26 19:44:38 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!new || !lst)
		return ;
	i = *lst;
	if (*lst)
	{
		while (i->next)
			i = i->next;
		i->next = new;
	}
	else
		*lst = new;
}
