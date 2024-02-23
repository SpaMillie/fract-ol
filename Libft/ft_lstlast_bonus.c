/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:17:59 by mspasic           #+#    #+#             */
/*   Updated: 2023/11/14 17:30:23 by mspasic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lst_nd;

	if (!lst)
		return (NULL);
	lst_nd = lst;
	while (lst_nd -> next != NULL)
	{
		lst_nd = lst_nd -> next;
	}
	return (lst_nd);
}
