/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:30:09 by jeujeon           #+#    #+#             */
/*   Updated: 2020/10/17 18:14:54 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (*lst == 0)
	{
		new->next = 0;
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	new->next = 0;
	*lst = tmp;
}
