/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:15:07 by weaz              #+#    #+#             */
/*   Updated: 2023/04/12 18:05:42 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	**path;
	char	**args;
}t_pipex;

char	**ft_get_path(char **envp);

char	*ft_get_cmd(char **paths, char *cmd);

void	ft_first_cmd(t_pipex pipex, char **av, char **envp);

void	ft_scnd_cmd(t_pipex pipex, char **av, char **envp);

void	ft_exit_msg(t_pipex *pipex, char *msg);

void	ft_exit(char *msg);

void	ft_free_args(char **args);

void	ft_free_all(t_pipex *pipex, int who);

#endif
