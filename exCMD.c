/*
  exCMD.c- file that helps execute built-in commands to reduce clutter
  Author: Will Bullock
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "exCMD.h"

extern char **environ;

/*
Author: Professor Signorile
Taken from environ.c on Canvas
Steps through all the environment variables
*/
void printEnv() {
    char **env = environ;
    while (*env) { printf("%s\n", *env++); }
}

//Executes the command within the child process
void runChild(char **args) {
    execvp(args[0], args);
    perror("Error: Command   could   not  be   executed");
    exit(1);
}

//Used for creation of new process using fork
void exProcess(char **args, int *pids, int *count) {
    int pid;
    switch(pid = fork()) {

        case(0):                        // Child's process
            runChild(args);
            break;
        case(-1):                         //Fork fails
            perror("Fork error.");
            exit(1);
        default: {                        // Parent's process
            int status;
            int childPID;

            pids[*count] = pid;
            childPID = waitpid(pid, &status, 0); //shed child resources, prevent zombie child
        }

    }
}

//Implements cd function and changes pwd in the environment
void exCD(char *path, int max) {
    char oldCWD[max];

    getcwd(oldCWD, sizeof(oldCWD));
    chdir(path);

    char newCWD[max];

    getcwd(newCWD, sizeof(newCWD));
    setenv("PWD", newCWD, 1);
    setenv("OLDPWD", oldCWD, 1);
}

//Prints last 5 PIDs created
void showPID(int *pidQ, int max) {
    for (int i = 0; i < max; i++) {
        if (pidQ[i] != 0) {
            printf("%i\n", pidQ[i]);
        }
    }
}
