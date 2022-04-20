#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_NUM_AGRS 64
#define MAX_CMD_SIZE 512
#define CMD_DELIMETER " \t\r\n\a"

void exec_command(char** args) {
  if (execvp(args[0], args) == -1) {
    // execvp failed
    printf("Invalid command!\n");
    exit(EXIT_FAILURE);
  };
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {

  if(argc < 2){
    printf("No command found!\n");
    return 0;
  }

  int child_pid = fork();
  if (child_pid == -1) {
    perror("fork failed!!");
    exit(EXIT_FAILURE);
  }

  if (child_pid == 0) {
    // parent
    // Wait for the child's termination
    waitpid(child_pid, NULL, 0);
  } else {
    // children
    // print PIDs
    printf("Child PID: %d Parent PID: %d\n", getpid(), getppid());
    // Execute the command
    exec_command(argv+1);
  }
}