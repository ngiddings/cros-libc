#include "stdio.h"

/*started by Kyle Clements
    all this will do is read one char from stdin.  Nothing more.
    stdin is typically 0 in the read call.*/
int getchar(){
    return fgetc(stdin);
}