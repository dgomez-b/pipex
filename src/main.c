/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:02 by minimarmeto       #+#    #+#             */
/*   Updated: 2024/02/13 16:39:48 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <pipex.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_multipid	pids;
	int			fd[2];

	if (argc != 5)
		error2("\e[31mError : Bad amount of arguments\e[0m", 0);
	if (access(argv[1], F_OK | R_OK) != 0)
		error();
	if (pipe(fd) < 0)
		error();
	pids.pid1 = fork();
	if (pids.pid1 < 0)
		error();
	if (pids.pid1 == 0)
		first_process(argv[1], argv[2], fd, envp);
	pids.pid2 = fork();
	if (pids.pid2 < 0)
		error();
	if (pids.pid2 == 0)
		last_process(argv[4], argv[3], fd, envp);
	close(fd[1]);
	waitpid(pids.pid1, (void *)0, 0);
	waitpid(pids.pid2, (void *)0, 0);
	return (0);
}
