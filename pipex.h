/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:09:03 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 18:40:04 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

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
	int		**pfd;
}	t_data;


char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

void	free_array(char **array);

int		ft_printf(const char *format, ...);

char	*get_path(char *cmd);

void	run_all_cmd(t_data data);

void	init_data(t_data *data, int ac, char **av);

void	free_data(t_data data);

void	close_all_fd(t_data data);

#endif