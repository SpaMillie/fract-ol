/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:08:33 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/15 19:39:44 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*n_lst;
	void	*temp_cont;

	if (!lst || !f || !del)
		return (NULL);
	n_lst = NULL;
	while (lst)
	{
		temp_cont = f(lst-> content);
		new = ft_lstnew(temp_cont);
		if (!new)
		{
			ft_lstclear (&n_lst, del);
			del (temp_cont);
			return (NULL);
		}
		ft_lstadd_back(&n_lst, new);
		lst = lst -> next;
	}
	return (n_lst);
}
