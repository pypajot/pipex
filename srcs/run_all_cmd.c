/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:50:00 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 17:50:35 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run_cmd_in(t_data data)
{
	int	cpid;
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.fd1, 0);
		dup2(data.pfd[0][1], 1);
		close_all_fd(data);
		execve(data.cmd_array[0].path, data.cmd_array[0].av, 0);
	}
}

void	run_cmd_i(t_data data, int i)
{
	int	cpid; 
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.pfd[i + 1][1], 1);
		dup2(data.pfd[i][0], 0);
		close_all_fd(data);
		execve(data.cmd_array[i + 1].path, data.cmd_array[i + 1].av, 0);
	}
}

void	run_cmd_out(t_data data, int i)
{
	int	cpid;
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.pfd[i][0], 0);
		dup2(data.fd2, 1);
		close_all_fd(data);
		execve(data.cmd_array[i + 1].path, data.cmd_array[i + 1].av, 0);
	}
}

void	run_all_cmd(t_data data)
{	
	int	i;
	
	i = 0;
	run_cmd_in(data);
	while (i < data.cmd_nbr - 2)
	{
		run_cmd_i(data, i);
		i++;
	}
	run_cmd_out(data, i);
	wait(0);
}
