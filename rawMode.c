#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "rawMode.h"

//struct for original terminal state
struct termios original_termios;

//error handling 
void kill(const char *e){
    perror(e);
    exit(1);
}

void enableRawMode(){
    //gets attributes of temrinal and inputs into the struct 
    if(tcgetattr(STDIN_FILENO, &original_termios) == -1){
        kill("tcgetattr");
    }
    atexit(disableRawMode);

    //struct used to maniputlate terminal state
    struct termios raw = original_termios;

    //Disable Ctrl-S, Ctrl-Q, fixes Ctrl-M, and other flags turned off for the terminal
    raw.c_iflag &= ~(BRKINT | INPCK | ISTRIP | IXON | ICRNL);

    //turns off output processing
    raw.c_oflag &= ~(OPOST);

    //sets character size to 8 bytes
    raw.c_cflag |= (CS8);

    /*turns off local flags, such as echo flag(input not shown in terminal), 
    canonical flag(reads input byte by byte), Ctrl-Z, Ctrl-C and Ctrl-v*/
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);

    //# of bytes needed for read function to return
    raw.c_cc[VMIN] = 0;
    //amount of time program waits for read function to return
    raw.c_cc[VTIME] = 1;

    //applies changes made in struct to the terminal
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1){
        kill("tcsetattr");
    }
}

void disableRawMode(){
    //returns original attributes of terminal
    if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios) == -1){
        kill("tcsetattr");
    }
}
