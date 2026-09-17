/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../include/strace.h"
#include "../include/syscall.h"

static void smart_free(char *a, char *b, char *c)
{
    if (a)
        free(a);
    if (b)
        free(b);
    if (c)
        free(c);
}

char *which(const char *name, const char **env)
{
    char *tmp = strdup(getpath(env));
    char *token = strtok(tmp, ":");
    char *cmd = malloc(PATH_MAX);

    if (!cmd || !tmp) {
        smart_free(cmd, tmp, NULL);
        return NULL;
    }
    while (token) {
        snprintf(cmd, PATH_MAX, "%s/%s", token, name);
        if (!access(cmd, X_OK)) {
            smart_free(tmp, NULL, NULL);
            return cmd;
        }
        token = strtok(NULL, ":");
    }
    smart_free(tmp, cmd, NULL);
    return NULL;
}

static void sub_loop(reg_t regs, syscall_t *table, args_t args)
{
    const char *syscall_name = NULL;

    syscall_name = table[regs.orig_rax].name;
    dprintf(1, "%s(", syscall_name);
    display_args(regs, table[regs.orig_rax], args);
}

void trace_loop(pid_t child, int status, reg_t regs, args_t args)
{
    int state = 0;

    while (1) {
        ptrace(PTRACE_SINGLESTEP, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFEXITED(status) || WIFSIGNALED(status))
            break;
        ptrace(PTRACE_GETREGS, child, 0, &regs);
        state = regs.orig_rax >= 0.0
            && regs.orig_rax < sizeof(table) / sizeof(*table);
        if (state)
            sub_loop(regs, table, args);
        if (state && handle_cmd_failure(regs))
            continue;
        if (state)
            dprintf(1, ") = %i\n", (int)regs.rax);
    }
}

static int sub_exec(pid_t child, int status, args_t args, const char **envp)
{
    char *w = which(args.av[0], envp);

    if (!w)
        dprintf(2, "which: no %s in (%s)\n", args.av[0], getpath(envp));
    waitpid(child, &status, 0);
    if (WIFEXITED(status) || WIFSIGNALED(status)) {
        smart_free(w, NULL, NULL);
        return 0;
    }
    dprintf(1, "execve(\"%s\", [", w);
    smart_free(w, NULL, NULL);
    return -1;
}

int trace_exec(pid_t child, args_t args, const char **envp)
{
    int status = 0;
    struct user_regs_struct regs;
    int nb_vars = get_nb_vars(envp);

    if (args.arg_p) {
        dprintf(1, "strace: Process %d attached\n", args.pid);
        waitpid(child, &status, 0);
    } else {
        if (!sub_exec(child, status, args, envp))
            return 0;
        for (int i = 0; args.av[i]; i++)
            dprintf(1, "%s\"%s\"", i ? ", " : "", args.av[i]);
        dprintf(1, "], %p /* %d vars */) = 0\n", &args.av, nb_vars);
    }
    trace_loop(child, status, regs, args);
    dprintf(1, "exit_group(%d) = ?\n", WEXITSTATUS(status));
    dprintf(1, "+++ exited with %d +++\n", WEXITSTATUS(status));
    return WEXITSTATUS(status);
}

int run_trace(args_t args, const char **envp)
{
    pid_t pid = fork();
    int err = 0;

    if (pid == -1) {
        perror("fork");
        exit(ERROR_CODE);
    }
    args.pid = pid;
    if (pid)
        return trace_exec(pid, args, envp);
    ptrace(PTRACE_TRACEME, 0, NULL, NULL);
    execvp(args.av[0], args.av);
    err = errno;
    if (err)
        dprintf(2, "strace: Can't stat '%s': %s\n",
            args.av[0], strerror(err));
    return 0;
}

int main(int argc, char **argv, const char **envp)
{
    args_t args = {0};
    pid_t pid;

    if (argc < 2 || argc > 5 || get_args(argc, argv, &args)) {
        dprintf(2, "strace: must have PROG [ARGS] or -p PID\n");
        dprintf(2, "Try 'strace -h' for more information.\n");
        exit(ERROR_CODE);
    }
    if (args.arg_p) {
        pid = args.pid;
        if (ptrace(PTRACE_ATTACH, pid, NULL, NULL) == -1) {
            perror("ptrace");
            exit(ERROR_CODE);
        }
        trace_exec(pid, args, envp);
    } else
        return run_trace(args, envp);
    return ERROR_CODE;
}
