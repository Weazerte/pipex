/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:46:35 by weaz              #+#    #+#             */
/*   Updated: 2023/04/12 15:36:45 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	ft_first_cmd(t_pipex pipex, char **av, char *envp[])
{
	dup2(pipex.pip[1], 1);
	close(pipex.pip[0]);
	dup2(pipex.infile, 0);
	pipex.args = ft_split(av[2], ' ');
	pipex.cmd = ft_get_cmd(pipex.path, pipex.args[0]);
	if (!pipex.cmd)
	{
		ft_msg("error cmd 1\n");
		ft_free_all(&pipex, 1);
		exit(1);
	}
	execve(pipex.cmd, pipex.args, envp);
}

void	ft_free_scnd_child(t_pipex *pipex)
{
	int	i;

	i = 0;
	close (pipex->infile);
	close(pipex->outfile);
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		i++;
	}
	i = 0;
	free(pipex->path);
	free(pipex->cmd);
	while (pipex->args[i])
	{
		free(pipex->args[i]);
		i++;
	}
	free(pipex->args);
}

void	ft_scnd_cmd(t_pipex pipex, char **av, char *envp[])
{
	dup2(pipex.pip[0], 0);
	close(pipex.pip[1]);
	dup2(pipex.outfile, 1);
	pipex.args = ft_split(av[3], ' ');
	pipex.cmd = ft_get_cmd(pipex.path, pipex.args[0]);
	if (!pipex.cmd)
	{
		ft_msg("error cmd 2\n");
		ft_free_scnd_child(&pipex);
		exit(1);
	}
	execve(pipex.cmd, pipex.args, envp);
}
