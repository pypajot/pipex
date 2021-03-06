/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:49:08 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 19:15:00 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_all_fd(t_data data)
{
	if (data.pfd[0][0] >= 0)
		close(data.pfd[0][0]);
	if (data.pfd[0][1] >= 0)
		close(data.pfd[0][1]);
	if (data.pfd[1][0] >= 0)
		close(data.pfd[1][0]);
	if (data.pfd[1][1] >= 0)
		close(data.pfd[1][1]);
	if (!data.hd && data.fd1 >= 0)
		close(data.fd1);
	if (data.fd2 >= 0)
		close(data.fd2);
}
