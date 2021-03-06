/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:50:00 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/07 20:37:19 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	stdin_to_pipe(t_data data)
{
	int		newfd;
	char	*str;
	int		cpid;

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
		close (newfd);
		exit (0);
	}
	if (cpid < 0)
		perror("");
	return (cpid);
}

static int	run_cmd_in(t_data data, char **envp)
{
	int	cpid;

	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.fd1, 0);
		dup2(data.pfd[0][1], 1);
		close_all_fd(data);
		if (data.fd1 < 0)
		{
			free_data(data);
			exit (0);
		}
		exec_cmd(data.cmd_arr[0].av[0], data.cmd_arr[0].av, envp);
		free_data(data);
		exit (0);
	}
	if (cpid < 0)
		perror("");
	return (cpid);
}

static int	run_cmd_i(t_data data, int i, char **envp)
{
	int	cpid;

	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.pfd[i % 2][0], 0);
		dup2(data.pfd[(i + 1) % 2][1], 1);
		close_all_fd(data);
		exec_cmd(data.cmd_arr[i + 1 - data.hd].av[0],
			data.cmd_arr[i + 1 - data.hd].av, envp);
		free_data(data);
		exit (0);
	}
	if (cpid < 0)
		perror("");
	close(data.pfd[i % 2][0]);
	close(data.pfd[i % 2][1]);
	return (cpid);
}

static int	run_cmd_out(t_data data, int i, char **envp)
{
	int	cpid;

	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.pfd[i % 2][0], 0);
		dup2(data.fd2, 1);
		close_all_fd(data);
		exec_cmd(data.cmd_arr[i + 1 - data.hd].av[0],
			data.cmd_arr[i + 1 - data.hd].av, envp);
		free_data(data);
		exit (0);
	}
	if (cpid < 0)
		perror("");
	return (cpid);
}

void	run_all_cmd(t_data data, char **envp)
{	
	int	i;
	int	status;

	i = -1;
	status = 0;
	pipe(data.pfd[0]);
	if (!data.hd)
		data.pid[0] = run_cmd_in(data, envp);
	else
		data.pid[0] = stdin_to_pipe(data);
	while (++i < data.cmd_nbr - 2 + data.hd)
	{
		pipe(data.pfd[(i + 1) % 2]);
		data.pid[i + 1] = run_cmd_i(data, i, envp);
	}
	data.pid[i + 1] = run_cmd_out(data, i, envp);
	if (!data.hd)
		close_all_fd(data);
	i = 0;
	waitpid(data.pid[i], &status, 0);
	while (++i < data.cmd_nbr && !data.hd)
		waitpid(data.pid[i], &status, 0);
}
