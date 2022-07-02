/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:48:32 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 22:54:39 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*static int	is_command(char *cmd)
{
	int	i;

	if (!cmd)
		return (1);
	i = -1;
	while (cmd[++i])
		if (cmd[i] == '/')
			return (0);
	return (1);
}*/

static char	**path_init(char **envp)
{
	int		i;
	char	**path_array;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp("PATH=", envp[i], 5))
			break ;
	if (!envp[i])
		return (0);
	path_array = ft_split(envp[i], ':');
	return (path_array);
}

char	**dup_builtin(char **av)
{
	int	i;
	char **new_av;

	i = -1;
	while (av[i])
		i++;
	new_av = (char **)malloc(sizeof(char *) * (i + 3));
	new_av[0] = ft_strdup("/bin/bash");
	new_av[1] = ft_strdup("-c");
	i = -1;
	while (av[++i])
		new_av[i + 2] = av[i];
	new_av[i + 2] = 0;
	return (new_av);
}

void	exec_cmd(char *cmd, char **av, char **envp)
{
	int		i;
	char	**path_array;
	char	*path;

	i = -1;
	path_array = path_init(envp);
	if (!path_array)
		return ;
	char **new_av = dup_builtin(av);
	execve("/bin/bash", new_av, envp);
	return;
	execve(cmd, av, envp);
	while (path_array[++i])
	{
		path = ft_strjoin(path_array[i], cmd, "/");
		av[0] = path;
		execve(path, av, envp);
		free(path);
	}
	av[0] = cmd;
	
	free_array(path_array);
	return /*(perror(cmd))*/;
}

/*char	*get_path(char *cmd, char **envp)
{
	char	*path;

	if (!is_command(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (perror(cmd), (void *)0);
	}
	path = cmd_path(cmd, envp);
	if (!path)
		return (ft_error(CMD_NOT_FOUND, cmd));
	return (path);
}*/
