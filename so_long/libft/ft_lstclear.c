/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloko <lloko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:57:34 by lloko             #+#    #+#             */
/*   Updated: 2022/01/29 17:15:02 by lloko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		i = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = i;
	}
	*lst = NULL;
}
