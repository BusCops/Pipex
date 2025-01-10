/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:41:40 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/10 18:50:54 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *file, int *fd, char *cmd, char **env);
{
	int	fd1;
	
	fd1 = open_file(file, 0);//close this files after
	dup2(fd1, STDIN_FILENO)
	dup2(fd[1], STDOUT_FILENO);
	exec_cmd(cmd, env);
}

void	main_process(char *file, int *fd, char *cmd, char **env);
{
	int	fd2;
	
	fd2 = open_file(file, 1)//close this files after
	dup2(fd2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	exec_cmd(cmd, env);
}

void	exec_cmd(char *cmd, char **env)
{
	char	**cmds;
	int		error_check;
	
	cmds = ft_split(cmd, " ");//need to be freed after
	error_check = execve(get_cmd_dir(env, cmd), cmds, env);
	if (error_check)
	{
		perror("\033[1;91mError excuting the cmd\33[00m");
		exit(1);
	}
}

int	main(int ac, char **av, char **env)
{
	int	p_id;
	int	fd[2];//need to check for this to be closed when finished
	
	args_checks(ac);
	if(pipe(fd) == -1)
	{
		perror("\033[1;91mPipe Error\33[00m");
		exit(1);
	}
	p_id = fork();
	if (p_id < 0)
	{
		perror("\033[1;91mFork Error\33[00m");
		exit(1);
	}
	else if (p_id == 0)
		child_procces(av[1], fd);
	else
	{
		wait();
		main_process(av[4], fd);
	}
	return (0);
}
