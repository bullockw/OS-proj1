/*
  myshell.c- creates a simple shell capable of program execution
  and built-in functions cd, exit, showPID
  Author: Will Bullock
*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "exCMD.h"

#define MAX_LINE 80
#define MAX_TOKS 10
#define PID_LIST 5


char *args[MAX_TOKS];
char string[MAX_LINE];
int pids[PID_LIST];
const char delimiters[] = " \n";

int getArguments(char *line, char **args);
void updatePIDList();

int main() {
      int pidCount = 0;

  while(1){

    int argcount;
    printf("prompt$>> ");
    fgets(string, MAX_LINE, stdin);
    argcount = getArguments(string,args);
    //printf("%s",string);

    if (strcmp(args[0], "\n") != 0 && argcount > 0 ) { //Check arguments entered

      if (strcmp("exit", args[0]) == 0){              // Check for exit
          printf("exit\n");
          exit(0);
      }
      else if (strcmp("showpid", args[0]) == 0) {    //Check show process id
          showPID(pids, PID_LIST);
      }
      else if (strcmp("environ", args[0]) == 0) {   //Check environment
          printEnv();
      }
      else if (strcmp("cd", args[0]) == 0) {       //Check change directory
          exCD(args[1], MAX_LINE);
      }
      else {                                      //Checks process id list, if 5 or more make room for next one
          if (pidCount == PID_LIST) {
              updatePIDList();
              pidCount = PID_LIST - 1;
          }
          exProcess(args, pids, &pidCount);
          pidCount++;
      }
    }


  }
}

//Reorganizes the PID list to add a new one
void updatePIDList() {
    for (int i = 0; i < PID_LIST - 1; i++) {   //moves each process up one spot, knocks off top one
        pids[i] = pids[i+1];
    }
    pids[PID_LIST - 1] = 0;
}

/*
Author: Professor Signorile
This is the getArguments() function used in strtok.c and demonstrated in lecture
I slightly modified it to add a condition,
which ensures the arguements stays under 10

*/
int getArguments(char *line, char **args){
    int argcount = 0;
    char *cp;
    cp = strdup (line);                         //Make writable copy.
    args[argcount] = strtok (cp, delimiters);   //get first token
    argcount++;
    while ( (args[argcount] = strtok (NULL, delimiters)) ){ //gets next token, end at NULL
      if (argcount > MAX_TOKS) {
          perror("Too many arguments given. Please try again.");
          return -1;
      }
        printf("%d. %s\n",argcount, args[argcount]);
        argcount++;
    }
    return argcount;
}
