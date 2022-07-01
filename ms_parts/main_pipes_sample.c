#include <unistd.h> // for pipe
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
// shell pipe
// cmd1 -> pipe -> cmd2 -> pipe -> cmd3
void connect_stdio_to_pipes(int prev_fds[], int next_fds[])
{
    if (prev_fds[0] >= 0)
    {
        dup2(prev_fds[0], 0);
        close(prev_fds[0]);
        close(prev_fds[1]);
    }
    if (next_fds[1] >= 0)
    {
        dup2(next_fds[1], 1);
        close(next_fds[1]);
        close(next_fds[0]);
    }
}

int main(int argc, char **argv, char **envp)
{
    char *cmd1[] = { "/usr/bin/yes", NULL };
    char *cmd2[] = { "/usr/bin/grep", "y", NULL };
    char *cmd3[] = { "/usr/bin/grep", "y", NULL };
    char *cmd4[] = { "/usr/bin/head", "-n", "10", NULL };
    char **cmds[5];
    cmds[0] = cmd1;
    cmds[1] = cmd2;
    cmds[2] = cmd3;
    cmds[3] = cmd4;
    cmds[4] = NULL;
    int i = 0;
    int cmds_count = 3;
    int prev_pipe_fds[2];
    int next_pipe_fds[2];
    next_pipe_fds[0] = -1;
    next_pipe_fds[1] = -1;
    while (i < cmds_count)
    {
        prev_pipe_fds[0] = next_pipe_fds[0];
        prev_pipe_fds[1] = next_pipe_fds[1];
        if (i != cmds_count - 1)
            pipe(next_pipe_fds);
        else
        {
            next_pipe_fds[0] = -1;
            next_pipe_fds[1] = -1;
        }
        if (fork() == 0)
        {
            connect_stdio_to_pipes(prev_pipe_fds, next_pipe_fds);
            char **cmd = cmds[i];
            execve(cmd[0], cmd, NULL);
        }
        close(prev_pipe_fds[0]);
        close(prev_pipe_fds[1]);
        i++;
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return (0);
}
