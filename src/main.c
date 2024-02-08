/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:25:02 by minimarmeto       #+#    #+#             */
/*   Updated: 2024/02/08 19:31:17 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <pipex.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (argc != 5)
	{
		ft_putendl_fd("\e[31mError : Bad amount of arguments\e[0m", 0);
		return (0);
	}
	if (access(argv[1], F_OK | R_OK) != 0)
		error();
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
