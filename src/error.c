/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:20:46 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/02/13 16:39:14 by dgomez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/// @brief Prints the error into stdout and exits program with errno value
void	error(void)
{
	perror("\e[31mError");
	ft_putstr_fd("\e[0m", 0);
	exit (errno);
}

/// @brief Prints the error into stdout and exits program with errno value
/// @param ser String error
/// @param err Exit value
void	error2(char *ser, int err)
{
	ft_putstr_fd("\e[31mError:", 0);
	ft_putstr_fd(ser, 0);
	ft_putendl_fd("\e[0m", 0);
	exit (err);
}
