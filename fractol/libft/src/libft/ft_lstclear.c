/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:10:26 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/09 11:12:53 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next_list;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next_list = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next_list;
	}
	*lst = ((void *)0);
}
