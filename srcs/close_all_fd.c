/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:49:08 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 20:00:21 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_all_fd(t_data data)
{
	int	i;

	i = -1;
	while (++i < data.cmd_nbr - 1 + data.hd)
	{
		close(data.pfd[i][0]);
		close(data.pfd[i][1]);
	}
	if (!data.hd)
		close(data.fd1);
	close(data.fd2);
}
