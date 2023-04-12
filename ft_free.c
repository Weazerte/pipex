/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:06:31 by weaz              #+#    #+#             */
/*   Updated: 2023/04/11 16:33:05 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_all(t_pipex *pipex, int who)
{
	int	i;

	i = 0;
	if (who == 0)
	{
		close (pipex->infile);
		close(pipex->outfile);
		while (pipex->path[i])
		{
			free(pipex->path[i]);
			i++;
		}
		free(pipex->path);
	}
	i = 0;
	if (who == 1)
	{
		free(pipex->cmd);
		while (pipex->args[i])
		{
			free(pipex->args[i]);
			i++;
		}
		free(pipex->args);
	}
}
