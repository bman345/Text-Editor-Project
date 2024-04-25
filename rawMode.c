#include "rawMode.h"
#include <stdlib.h>

//struct for original terminal state
struct termios original_termios;

void enableRawMode(){
    //gets attributes of temrinal and inputs into the struct 
    tcgetattr(STDIN_FILENO, &original_termios);
    atexit(disableRawMode);

    //struct used to maniputlate terminal state
    struct termios raw = original_termios;

    raw.c_iflag &= ~(IXON);
    /*turns off local flags, such as echo flag(input not shown in terminal), 
    canonical flag(reads input byte by byte), and control signals(Z and C)*/
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);

    //applies changes made in struct to the terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableRawMode(){
    //returns original attributes of terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}