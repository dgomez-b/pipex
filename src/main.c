/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minimarmeto <minimarmeto@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:02 by minimarmeto       #+#    #+#             */
/*   Updated: 2024/02/08 18:54:46 by minimarmeto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <pipex.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/// @brief Frees a matrix
/// @param mat matrix to be freed
void	freemat(void **mat)
{
	unsigned int	i;

	if (!mat)
		return ;
	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

/// @brief Prints the error into stdout and exits program with errno value
void	error()
{
	perror("\e[31mError");
	exit (errno);
}

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

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
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

int main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];
	
	if (argc != 5)
	{
		ft_putendl_fd("\e[31mError : Bad amount of arguments\e[0m", 0);
		return (0);
	}
	if (pipe(fd) < 0)
		error();
	pid = fork();
	if (pid < 0)
		error();
	if (pid == 0)
		first_process(argv[1], argv[2], fd, envp);
	last_process(argv[4], argv[3], fd, envp);
	return (0);
}
