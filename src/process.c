/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:23:42 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/02/13 15:30:38 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <pipex.h>
#include <fcntl.h>
#include <unistd.h>

/// @brief Executes the first command introduced
/// @param filename File where command will take information
/// @param comline The command with its arguments
/// @param fd pipe
/// @param envp environment data
void	first_process(char *filename, char *comline, int *fd, char **envp)
{
	int		file;
	char	**cmd;
	char	*path;

	file = open(filename, O_RDONLY);
	if (file == -1)
		error();
	cmd = ft_split(comline, ' ');
	path = get_path(*cmd, envp);
	close(fd[0]);
	dup2(fd[1], 1);
	dup2(file, 0);
	if (execve(path, cmd, envp) == -1)
	{
		freemat((void **)cmd);
		error();
	}
}

/// @brief Executes the last command introduced
/// @param filename File where command will take information
/// @param comline The command with its arguments
/// @param fd pipe
/// @param envp environment data
void	last_process(char *filename, char *comline, int *fd, char **envp)
{
	int		file;
	char	**cmd;
	char	*path;

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		error();
	dup2(fd[0], 0);
	dup2(file, 1);
	close(fd[1]);
	cmd = ft_split(comline, ' ');
	path = get_path(*cmd, envp);
	if (execve(path, cmd, envp) == -1)
	{
		freemat((void **)cmd);
		error();
	}
}
