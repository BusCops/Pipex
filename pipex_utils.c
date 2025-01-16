/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:46:54 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/16 11:29:48 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_printerror(char *cmd, char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, ft_strlen(msg));
	write(2, ": ", 2);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	return (fd);
}

char	**ft_getenv(char *cmd, char *str, char **env)
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
	ft_printerror(cmd, "Command not found");
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
			return (free(tmp1), tmp2);
		i++;
		free(tmp1);
		free(tmp2);
	}
	ft_printerror(cmd, "Command not found");
	return (NULL);
}

char	*get_cmd_dir(char **env, char *cmd)
{
	char	**all_cmd_path;
	char	**cmd_line;
	char	*cmd_dir;

	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	all_cmd_path = ft_getenv(cmd, "PATH", env);
	if (!all_cmd_path)
		return (NULL);
	cmd_line = ft_split_custom(cmd);
	if (!cmd_line)
	{
		free_array(all_cmd_path);
		return (NULL);
	}
	cmd_dir = check_access(all_cmd_path, cmd_line[0]);
	return (free_array(cmd_line), free_array(all_cmd_path), cmd_dir);
}
