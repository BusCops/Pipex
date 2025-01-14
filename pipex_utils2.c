/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:50:15 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/14 12:07:05 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_checks(int ac)
{
	if (ac != 5)
	{
		ft_putstr_fd("\033[1;91mError: Wrong argument number\n\33[00m", 2);
		exit(1);
	}
}

void	fork_error(int p_id)
{
	if (p_id < 0)
	{
		perror("\033[1;91mFork Error\33[00m");
		exit(1);
	}
}

void	pipe_error(int pipe)
{
	perror("\033[1;91mPipe Error\33[00m");
	exit(1);
}
