/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:52:49 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/29 21:30:35 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_data(t_data data)
{
	int	i;

	i = 0;
	while (i < data.cmd_nbr)
	{
		if (data.cmd_arr[i].av != 0)
			free_array(data.cmd_arr[i].av);
		i++;
	}
	free(data.pid);
	free(data.cmd_arr);
}
