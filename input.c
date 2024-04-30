#include "input.h"
#include <stdlib.h>

//input macros
#define CTRL_KEY(k) ((k) & 0x1f)

//reads input from user
char textEditorReadKey(){
    int nread;
    char input;

    while((nread = read(STDIN_FILENO, &input, 1) == -1)){
        if(nread == -1 && errno != EAGAIN){
            kill("read");
        }
    }
    return input;
}
//detects various key combinations for input in text edtior
void textEditorProcessKeypress(){
    char input = textEditorReadKey();

    switch (input){
    case CTRL_KEY('q'):
        exit(0);
        break;
    }
}