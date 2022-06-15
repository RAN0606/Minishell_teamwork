/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qxia <qxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:02:00 by qxia              #+#    #+#             */
/*   Updated: 2022/06/13 18:25:08 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_parents_process(char *input2, t_data *data, int pid, int *fd)
{
    int oldfd;
    int status;

    if (waitpid(pid, &status, 0) != pid)
        exit(EXIT_FAILURE);
    oldfd = dup(0);
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);
    //parser;
    dup2(oldfd, 0);
    close(oldfd);
}

int ft_pipe(char *input1, char *input2, t_data *data)
{
    pid_t   pid;
    int     fd[2];
    // fd[0] - read
    // fd[1] - write 
    if (pipe(fd) == -1)
        exit(EXIT_FAILURE);
    pid = fork();
    if (pid == 0)
    {
        free(input2);
        dup2(fd[1], 1);
        close(fd[0]);
        close(fd[1]);
        //basic
    }
    else if (pid < 0)
        exit(EXIT_FAILURE);
    else
    {
        free(input1);
        input1 = NULL;
        ft_parents_process(input2, data, pid, fd);
    }
    return (1);
}