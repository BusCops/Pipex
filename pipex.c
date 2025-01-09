/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:41:40 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/09 18:34:01 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd1;
	int 	fd2;
	int		errore_check;
	char	*dir;
	char	**cmd_line;
	
	(void)errore_check;
	args_checks(ac);
	fd1 = open_check(open(av[1], O_RDONLY));
	fd2 = open_check(open(av[4], O_RDONLY));
	dir = get_cmd_dir(env, av[2]);
	cmd_line = ft_split(av[2], ' ');
	int ee = execve(dir, cmd_line, env);
	printf("%i", ee);
}
