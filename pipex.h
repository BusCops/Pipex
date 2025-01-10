/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenzaho <abenzaho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 10:55:25 by abenzaho          #+#    #+#             */
/*   Updated: 2025/01/10 18:59:37 by abenzaho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include <sys/wait.h>

void	args_checks(int ac);
int     open_file(char *file, int mode);
char	**ft_getenv(char *str, char **env);
char	*check_access(char **path_cmd, char *cmd);
char	*get_cmd_dir(char **env, char *cmd);
void	exec_cmd(char *cmd, char **env);
void	main_process(char *file, int *fd, char *cmd, char **env);
void	child_process(char *file, int *fd, char *cmd, char **env);

#endif
