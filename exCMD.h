/*
  exCMD.h- header file for exCMD.c
  Author: Will Bullock
*/
#ifndef _execCMD_h
#define _execCMD_h


void printEnv();
void runChild(char **args);
void exProcess(char **args, int *pids, int *count);
void exCD(char *path, int max);
void showPID(int *pidQ, int max);


#endif
