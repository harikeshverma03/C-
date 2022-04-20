#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PRE_EXEC_PATH "./build/pre"
#define SORT_EXEC_PATH "./build/sort"

int main(void) {
  int pipe_fds[2];

  if (pipe(pipe_fds) == -1) {
    perror("pipe failed!");
    exit(EXIT_FAILURE);
  }

  int ret = fork();

  if (ret == -1) {
    perror("fork failed!!");
    exit(EXIT_FAILURE);
  }

  if (ret == 0) {
    dup2(pipe_fds[1], STDOUT_FILENO);
    close(pipe_fds[0]);
    close(pipe_fds[1]);
    execl(PRE_EXEC_PATH, "pre", (char *)0);
    perror("execl() failed!");
    exit(EXIT_FAILURE);
  } else {
    close(pipe_fds[1]);
    dup2(pipe_fds[0], STDIN_FILENO);
    close(pipe_fds[0]);
    execl(SORT_EXEC_PATH, "sort", (char *)0);
    perror("execl() failed!");
    exit(EXIT_FAILURE);
  }
}