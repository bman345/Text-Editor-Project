#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <ctype.h>
#include <errno.h>


void enableRawMode();
void disableRawMode();
void kill(const char *e);
