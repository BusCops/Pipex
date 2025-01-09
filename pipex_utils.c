/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:54 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/09 17:25:12 by abenzaho         ###   ########.fr       */
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

int	open_check(int fd)
{
	if (fd < 0)
	{
		perror("\033[1;91mError opening file\33[00m");
		exit(1);
	}
	return (fd);
}

char	**ft_getenv(char *str, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (env[i])
	{
		if (ft_strncmp(str, env[i], len) == 0 && env[i][len] == '=')
			return (ft_split(env[i] + len + 1, ':'));
		i++;
	}
	ft_putstr_fd("\033[1;91mNo environment variable found\n\33[00m", 2);
	return (NULL);
}

char	*check_access(char **path_cmd, char *cmd)
{
	int		i;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (path_cmd[i])
	{
		tmp1 = ft_strjoin(path_cmd[i], "/");
		tmp2 = ft_strjoin(tmp1, cmd);
		if (access(tmp2, F_OK | X_OK) == 0)
			return (free(tmp1), free(tmp2), ft_strdup(path_cmd[i]));
		i++;
		free(tmp1);
		free(tmp2);
	}
	ft_putstr_fd("\033[1;91mCommand not found: \33[00m", 2);
	ft_putstr_fd(cmd, 2);
	exit(1);
}
