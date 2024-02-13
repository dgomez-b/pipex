/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:05:14 by minimarmeto       #+#    #+#             */
/*   Updated: 2024/02/13 14:53:18 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_multipid
{
	int	pid1;
	int	pid2;
}	t_multipid;

void	first_process(char *filename, char *comline, int *fd, char **envp);
void	last_process(char *filename, char *comline, int *fd, char **envp);
char	*get_path(char *comname, char **envp);
void	freemat(void **mat);
void	error(void);

#endif