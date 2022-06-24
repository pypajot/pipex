/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:48:32 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/24 19:57:23 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	is_command(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		if (cmd[i] == '/')
			return (0);
	return (1);
}

static char	**path_init(char **envp)
{
	int		i;
	char	**path_array;

	i = -1;
	while (envp[++i])
		if (!ft_strncmp("PATH", envp[i], 4))
			break ;
	if (!envp[i])
		return (0);
	path_array = ft_split(envp[i], ':');
	return (path_array);
}

char	*cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**path_array;
	char	*path;
	
	i = -1;
	path_array = path_init(envp);
	while (path_array[++i] && path_array != 0)
	{
		path = ft_strjoin(path_array[i], cmd, "/");
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	if (!path_array[i])
	{
		free_array(path_array);
		return (0);
	}
	free_array(path_array);
	return (path);
}

char	*get_path(char *cmd, char **envp)
{
	char *path;

	if (!is_command(cmd))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (ft_error(NO_SUCH_FILE, cmd));
	}
	path = cmd_path(cmd, envp);
	if (!path)
		return (ft_error(CMD_NOT_FOUND, cmd));
	return (path);
}
