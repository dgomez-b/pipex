/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minimarmeto <minimarmeto@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:02 by minimarmeto       #+#    #+#             */
/*   Updated: 2024/02/08 10:25:26 by minimarmeto      ###   ########.fr       */
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
		free(mat[i]);
	free(mat);
}

/// @brief Prints the error into stdout and exits program with errno value
void	error()
{
	perror("\e[31mError");
	exit (errno);
}

void	first_process(char *filename/*, char *comline*/, int *fd, char **envp)
{
	int		file;
	pid_t	pid;
	char	*cmd[3] = {"/bin/ls", "-l", (void *)0};

	pid = fork();
	if (pid < 0)
		error();
	if (pid == 0)
	{
		file = open(filename, O_RDONLY);
		if (file == -1)
			error();
		dup2(fd[1], 1);
		dup2(file, 0);
		close(fd[0]);
		execve(*cmd, cmd, envp);
	}
	waitpid(pid, (void *)0, 0);
}

void	last_process(char *filename/*, char *comline*/, int *fd, char **envp)
{
	int		file;
	pid_t	pid;
	char	*cmd[3] = {"/bin/cat", "-e", (void *)0};

	pid = fork();
	if (pid < 0)
		error();
	if (pid == 0)
	{
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
		if (file == -1)
			error();
		dup2(fd[0], 0);
		dup2(file, 1);
		execve(*cmd, cmd, envp);
		close(fd[1]);
	}
	waitpid(pid, (void *)0, 0);
}

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	
	if (argc != 5)
	{
		ft_putendl_fd("\e[31mError : Bad amount of arguments\e[0m", 0);
		return (0);
	}
	if (pipe(fd) < 0)
		error();
	first_process(argv[1]/*, argv[2]*/, fd, envp);
	last_process(argv[4]/*, argv[3]*/, fd, envp);
	return (0);
}
