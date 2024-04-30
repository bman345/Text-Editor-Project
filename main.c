#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "rawMode.h"
#include "input.h"



int main(){

    enableRawMode();

    //implementation of processing keypresses
    while(1){
        textEditorProcessKeypress();
    }

    
    return 0;
}


