# Operating Systems Programming Project 1
*Author: Will Bullock*


## Contents:
`myshell.c`
  * The central file for the implementation of the basic shell
  * Can run programs as well as built-in fucntions:
    * cd- to change the current working directory
    * exit- terminates the currently running shell process
    * showpid- shows the last 5 child processes created by the shell
    * environ- returns the environment of the process
 
 `exCMD.c`
  * separate helper file used for controlling parent/child processes
  * carries out the execution of all the functions but exit
  
`exCMD.h`
  * header file inititializing the fucntions used in exCMD.c
  
## Compiling & Running
  1. Place the files *myshell.c*, *exCMD.c*, and *exCMD.c* in the same directory.
  2. From the terminal, navigate to the directory where all the files are placed.
  3. Compile the files using `gcc myshell.c exCMD.c -o myshell`
  4. Run `./myshell`
  5. Enjoy your new shell!
  
## Challenges
  * Getting the prompt to show the current directory
    - I thought once I figured out to change the cwd in the environment I would easily be able to display that value as the prompt, but I ran out of time and energy to actually make it happen. I struggled with transfering that value between functions and it turned into pointer overload.
  * Remembering c syntax and conventions
    - I spent a lot of the project referencing the C tutorials because I overestimated how much I actually remembered from CSCI2272.

## Sources
  * I used Canvas for referencing class materials and lecture notes on processes, forking, and exec
  * I also inserted a few snippets of code from Professor Signorile which I attributed to him in the comments of the code
  * StackOverflow 
  * The drexler C tutorial 
