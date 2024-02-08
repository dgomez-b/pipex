/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-b <dgomez-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:20:46 by dgomez-b          #+#    #+#             */
/*   Updated: 2024/02/08 19:50:16 by dgomez-b         ###   ########.fr       */
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
