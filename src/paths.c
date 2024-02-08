/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:22:04 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/02/08 19:32:28 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <pipex.h>
#include <unistd.h>
#include <stdlib.h>

static char	**environment_paths(char **envp)
{
	int	i;

	if (!envp)
		return ((void *)0);
	i = 0;
	while (envp[i])
		if (ft_strncmp(envp[i++], "PATHS", 4) == 0)
			return (ft_split(envp[--i] + 5, ':'));
	return ((void *)0);
}

/// @brief Gets the path where the command is located
/// @param comname The name of the command to search
/// @param envp Environment data
/// @return The path where the command is located or (void *)0 if command
/// couldn't be found
char	*get_path(char *comname, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	if (!comname)
		return (0);
	comname = ft_strjoin("./", comname);
	if (access(comname, F_OK | R_OK) == 0)
		return (comname);
	paths = environment_paths(envp);
	if (!paths)
		return ((void *)0);
	i = 0;
	path = (void *)0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i++], comname + 1);
		if (access(path, F_OK | R_OK) == 0)
			break ;
		free(path);
		path = (void *)0;
	}
	freemat((void **)paths);
	free(comname);
	return (path);
}
