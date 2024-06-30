/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <jichompo@>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:16:22 by jichompo          #+#    #+#             */
/*   Updated: 2024/02/08 22:16:46 by jichompo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_curr;
	t_list	*dummy;

	if (!f)
		return (NULL);
	dummy = ft_lstnew(NULL);
	if (!dummy)
		return (NULL);
	new_curr = dummy;
	while (lst != NULL)
	{
		new_curr->next = ft_lstnew((*f)(lst->content));
		if (new_curr->next == NULL)
		{
			ft_lstclear(&(dummy->next), del);
			free(dummy);
			return (NULL);
		}
		lst = lst->next;
		new_curr = new_curr->next;
	}
	new_curr = dummy->next;
	free(dummy);
	return (new_curr);
}
