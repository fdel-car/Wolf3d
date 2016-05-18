/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:48:12 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/08 19:34:43 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddn(t_list **alst, t_list *new, size_t n)
{
	t_list *temp;
	t_list *temp2;

	temp = *alst;
	while (temp->next && n > 0)
	{
		if (n == 1)
		{
			temp2 = temp->next;
			temp->next = new;
			new->next = temp2;
		}
		else
			temp = temp->next;
		n--;
	}
	if (n > 0)
		ft_lstaddend(alst, new);
}
