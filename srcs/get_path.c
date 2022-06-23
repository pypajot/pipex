/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:48:32 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 18:31:04 by ppajot           ###   ########.fr       */
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

static char	**path_init(void)
{
	char **path_array;
	
	path_array = (char **)malloc(11 * sizeof(char *));
	path_array[0] = ft_strdup("/mnt/nfs/homes/ppajot/bin/");
	path_array[1] = ft_strdup("/usr/local/sbin/");
	path_array[2] = ft_strdup("/usr/local/bin/");
	path_array[3] = ft_strdup("/usr/sbin/");
	path_array[4] = ft_strdup("/usr/bin/");
	path_array[5] = ft_strdup("/sbin/");
	path_array[6] = ft_strdup("/bin/");
	path_array[7] = ft_strdup("/usr/games/");
	path_array[8] = ft_strdup("/usr/local/games/");
	path_array[9] = ft_strdup("/snap/bin/");
	path_array[10] = 0;
	return (path_array);
}

char	*get_path(char *cmd)
{
	char	**path_array;
	char	*path;
	int		i;
	
	if (!is_command(cmd))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		else
			exit (0);
	}
	i = -1;
	path_array = path_init();
	while (++i < 10)
	{
		path = ft_strjoin(path_array[i], cmd);
		if (access(path, F_OK) == 0)
			break ;
		free(path);
	}
	free_array(path_array);
	if (i == 10)
		exit (0);
	return (path);
}