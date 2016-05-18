/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:10:51 by fdel-car          #+#    #+#             */
/*   Updated: 2015/12/15 18:51:30 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_lst(t_list **alst)
{
	t_list *temp;

	temp = *alst;
	while (temp)
	{
		ft_putstr(temp->content);
		temp = temp->next;
	}
}
