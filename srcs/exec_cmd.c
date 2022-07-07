/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:48:32 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/07 20:36:43 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

static char	**dup_builtin(char **av)
{
	int		i;
	char	**new_av;

	i = 0;
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
	char	**new_av;

	i = -1;
	execve(cmd, av, envp);
	path_array = path_init(envp);
	while (path_array != 0 && path_array[++i])
	{
		path = ft_strjoin(path_array[i], cmd, "/");
		av[0] = path;
		execve(path, av, envp);
		free(path);
	}
	av[0] = cmd;
	new_av = dup_builtin(av);
	execve("/bin/bash", new_av, envp);
	free_array(path_array);
	free_array(new_av);
	return ;
}
