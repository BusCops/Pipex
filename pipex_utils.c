/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:54 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/03 12:05:31 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	args_checks(int ac)
{
    if (ac != 5)
	{
		ft_putstr_fd("Error: Wrong argument number\n", 2)
		exit(1);
	}
}