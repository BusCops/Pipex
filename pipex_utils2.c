/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:15 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/14 13:14:14 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_checks(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("Error: Wrong argument number\n", 2);
		exit(1);
	}
}

void	fork_error(int p_id)
{
	if (p_id < 0)
	{
		perror("Fork Error");
		exit(1);
	}
}

void	pipe_error(void)
{
	perror("Pipe Error");
	exit(1);
}
