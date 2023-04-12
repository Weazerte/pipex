/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eaubry <eaubry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:08:00 by weaz              #+#    #+#             */
/*   Updated: 2023/04/12 14:54:08 by eaubry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **envp)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		++envp;
	if (*envp)
		return (ft_split(*envp + 5, ':'));
	else
		return (ft_split("", 'c'));
}

char	*ft_get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*cmd_result;
	int		i;

	if (access(cmd, 0) == 0)
		return (cmd);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd_result = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_result, 0) == 0)
			return (cmd_result);
		free(cmd_result);
		++i;
	}
	return (NULL);
}
