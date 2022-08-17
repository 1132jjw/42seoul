/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:51:06 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/25 17:08:43 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	if (lst == 0 || f == 0)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, next);
	}
	return (head);
}
