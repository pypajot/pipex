/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:53:16 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/25 18:14:39 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_alloc(t_data data)
{
	int	i;

	i = 0;
	if (!data.pfd || !data.cmd_array)
		return (0);
	while (i < data.cmd_nbr)
	{
		if (!data.cmd_array[i].av)
			return (0);
		if (i != data.cmd_nbr - 1 + data.hd)
			if (!data.pfd[i])
				return (0);
		i++;
	}
	return (1);
}
