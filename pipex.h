/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:09:03 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/22 20:47:24 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

# define BUFFER_SIZE 1

typedef struct s_cmd
{
	char	*path;
	char	**av;
}	t_cmd;


typedef struct s_data
{
	int		fd1;
	int		fd2;
	int		cmd_nbr;
	t_cmd	*cmd_array;
	int		*pfd[2];
}	t_data;


char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

void	free_array(char **array);

int			ft_printf(const char *format, ...);

char	*get_path(char *cmd);

char	**fill_av(char *str, char **cmd);

#endif