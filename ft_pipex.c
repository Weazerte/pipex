/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:58:02 by weaz              #+#    #+#             */
/*   Updated: 2023/04/12 14:40:21 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char *envp[])
{
	t_pipex	pipex;

	if (ac != 5)
		ft_exit("erreur input\n");
	pipex.infile = open(av[1], O_RDONLY);
	pipex.outfile = open(av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 00644);
	if (pipex.infile == -1)
		ft_exit_msg(&pipex, "erreur infile\n");
	if (pipex.outfile == -1)
		ft_exit_msg(&pipex, "error outfile\n");
	if (pipe(pipex.pip) == -1)
		ft_exit_msg(&pipex, "error pipe\n");
	pipex.path = ft_get_path(envp);
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		ft_first_cmd(pipex, av, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		ft_scnd_cmd(pipex, av, envp);
	(close(pipex.pip[1]), close(pipex.pip[0]));
	(waitpid(pipex.pid1, NULL, 0), waitpid(pipex.pid2, NULL, 0));
	ft_free_all(&pipex, 0);
	return (0);
}
