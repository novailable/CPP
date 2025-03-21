#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int tmp;

int    w_error(char *args)
{
    int i = 0;
    while (args[i])
        i++;
    write(2, args, i);
    return (1);
}

int exe_cd(char **argv, int count)
{
    if (count != 2)
        return (w_error("error: cd: bad arguments\n"));
    if (chdir(argv[1]) == -1)
        return (w_error("error: cd: cannot change directory to "), w_error(argv[1]), w_error("\n"));
    return (0);
}

void    print_array(char **array)
{
    for (int i = 0; array[i]; i++)
        printf("%s, ", array[i]);
    printf("\n");
}

int exe_cmd(char **argv, int i, char **envp)
{
    int pid;
    
    int p = (argv[i] && !strcmp(argv[i], "|"));
    int status;
    int p_fd[2];

    if (p && pipe(p_fd) == -1)
        return (w_error("error: fatal\n"));
    pid = fork();
    if (pid == 0)
    {
        argv[i] = 0;
        // print_array(argv);
        dup2(tmp, 0);
        close(tmp);
        if (p)
        {
            dup2(p_fd[1], 1);
            close(p_fd[0]), close(p_fd[1]);
        }
        if (!argv[0])
            exit(0);
        execve(argv[0], argv, envp);
        w_error("error : cannot execute ");
        w_error(argv[0]);
        return (w_error("\n"));
    }
    if (p)
        dup2(p_fd[0], tmp), close(p_fd[1]), close(p_fd[0]);
    else
        dup2(tmp, 0);
    waitpid(pid, &status, 0);
    return (WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
    int i;
    int status;
    
    (void)argc;
    tmp = dup(0);
    while (*argv && *++argv)
    {
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (!strcmp(*argv, "cd"))
            status = exe_cd(argv, i);
        else
            status = exe_cmd(argv, i, envp);
        argv += i;
    }
    dup2(tmp, 0);
    close(tmp);
    return (status);
}
