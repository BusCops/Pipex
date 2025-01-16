/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:41:40 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/16 11:14:17 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *file, int *fd, char *cmd, char **env)
{
	int	fd1;

	fd1 = open_file(file, 0);
	dup2(fd1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(fd1);
	exec_cmd(cmd, env);
}

void	child2_process(char *file, int *fd, char *cmd, char **env)
{
	int	fd2;

	fd2 = open_file(file, 1);
	dup2(fd2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(fd2);
	exec_cmd(cmd, env);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**cmds;
	char	*cmd_dir;

	cmds = ft_split_custom(cmd);
	if (!cmds)
	{
		perror("Error splitting command");
		exit(1);
	}
	cmd_dir = get_cmd_dir(env ,cmds[0]);
	if (!cmd_dir)
	{
		free_array(cmds);
		exit(1);
	}
	execve(cmd_dir, cmds, env);
	perror("Error excuting the cmd");
	free_array(cmds);
	exit(1);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int ac, char **av, char **env)
{
	int	p_id;
	int	p_id2;
	int	fd[2];

	args_checks(ac, av);
	if (pipe(fd) == -1)
		pipe_error();
	p_id = fork();
	fork_error(p_id);
	if (p_id == 0)
		child_process(av[1], fd, av[2], env);
	close(fd[1]);
	p_id2 = fork();
	fork_error(p_id2);
	if (p_id2 == 0)
		child2_process(av[4], fd, av[3], env);
	close(fd[0]);
	waitpid(p_id2, NULL, 0);
	waitpid(p_id, NULL, 0);
	return (0);
}
