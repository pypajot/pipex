/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:52:49 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/25 15:47:35 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_data(t_data data)
{
	int	i;

	i = 0;
	while (i < data.cmd_nbr)
	{
		if (data.cmd_array[i].av != 0)
			free_array(data.cmd_array[i].av);
		if (i != data.cmd_nbr - 1 + data.hd)
			if (data.pfd[i] != 0)
				free(data.pfd[i]);
		i++;
	}
	free(data.pfd);
	free(data.cmd_array);
}
