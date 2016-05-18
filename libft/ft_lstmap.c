/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:04:37 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/16 22:16:24 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;

	if (!lst)
		return (NULL);
	result = ft_lstnew(lst->content, lst->content_size);
	result = f(lst);
	if (lst->next)
	{
		result->next = ft_lstmap(lst->next, f);
	}
	return (result);
}
