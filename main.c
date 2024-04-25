#include "rawMode.h"



int main(){

    enableRawMode();

    char input;

    //reads input byte by byte and outputs it, 
    while(read(STDERR_FILENO, &input, 1) == 1 && input != 'q'){
        if(iscntrl(input)){
            printf("%d\n", input);
        }
        printf("%d ( '%c' )\n", input, input);
    }

    return 0;
}
