/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:41:40 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/09 17:21:11 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd1;
	int 	fd2;
	char	**all_cmd_path;
	char	*cmd_dir;
	char	**cmd_line;
	
	args_checks(ac);
	fd1 = open_check(open(av[1], O_RDONLY));
	fd2 = open_check(open(av[4], O_RDONLY));
	if(!(all_cmd_path = ft_getenv("PATH", env)))
		exit(1);
	cmd_line = ft_split(av[2], ' ');
	printf("%s",cmd_dir = check_access(all_cmd_path, cmd_line[0]));
	
}
