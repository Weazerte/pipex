/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_msg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:16:24 by weaz              #+#    #+#             */
/*   Updated: 2023/04/12 14:46:18 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	ft_exit_msg(t_pipex *pipex, char *msg)
{
	close(pipex->infile);
	close(pipex->outfile);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
