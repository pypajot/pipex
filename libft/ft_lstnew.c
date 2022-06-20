/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:17:37 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/17 21:06:26 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newelem;

	newelem = malloc(sizeof(t_list));
	if (newelem == 0)
		return (0);
	newelem->content = content;
	newelem->next = 0;
	return (newelem);
}
