/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:09:03 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 22:06:53 by ppajot           ###   ########.fr       */
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

# define CMD_NOT_FOUND 1
# define NO_SUCH_FILE 2
# define NOT_ENOUGH_ARG 3
# define INVALID_ARG 4

typedef struct s_cmd
{
	char	*path;
	char	**av;
}	t_cmd;

typedef struct s_data
{
	int		fd1;
	int		fd2;
	int		hd;
	char	*lim;
	int		cmd_nbr;
	t_cmd	*cmd_arr;
	int		pfd[2][2];
	int		*pid;
}	t_data;

char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2, char *c);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *str1, char *str2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	free_array(char **array);

int		ft_printf(const char *format, ...);

char	*get_next_line(int fd);

void	exec_cmd(char *cmd,char **av, char **envp);

char	*get_path(char *cmd, char **envp);

void	run_all_cmd(t_data data, char **envp);

int		init_data(t_data *data, int ac, char **av);

void	free_data(t_data data);

void	close_all_fd(t_data data);

char	*ft_error(int err, char *str);

#endif