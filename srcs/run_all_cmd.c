/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:50:00 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 21:12:31 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	stdin_to_pipe(t_data data)
{
	int		newfd;
	char	*str;
	int 	cpid;

	cpid = fork();
	if (cpid == 0)
	{
		newfd = dup(data.pfd[0][1]);
		close_all_fd(data);
		str = get_next_line(0);
		while (ft_strcmp(str, data.lim) != 10)
		{
			write(newfd, str, ft_strlen(str));
			free(str);
			str = get_next_line(0);
		}
		free(str);
		free_data(data);
		exit (0);
	}
}

void	run_cmd_in(t_data data)
{
	int	cpid;
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.fd1, 0);
		dup2(data.pfd[0][1], 1);
		close_all_fd(data);
		if (data.cmd_array[0].path == 0)
		{
			free_data(data);
			exit (0);
		}		
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
		if (data.cmd_array[i + 1 - data.hd].path == 0)
		{
			free_data(data);
			exit (0);
		}
		execve(data.cmd_array[i + 1 - data.hd].path, data.cmd_array[i + 1 - data.hd].av, 0);
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
		if (data.cmd_array[i + 1 - data.hd].path == 0)
		{
			free_data(data);
			exit (0);
		}
		execve(data.cmd_array[i + 1 - data.hd].path, data.cmd_array[i + 1 - data.hd].av, 0);
	}
}

void	run_all_cmd(t_data data)
{	
	int	i;
	
	i = -1;
	if (!data.hd)
		run_cmd_in(data);
	else
		stdin_to_pipe(data);
	while (++i < data.cmd_nbr - 2 + data.hd)
		run_cmd_i(data, i);
	run_cmd_out(data, i);
	wait(0);
}
