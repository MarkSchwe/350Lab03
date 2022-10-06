/*
LAB03 TASK 01
Mark Schweitzer
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//simple program that reads each byte individually from a process that is piped in from the command line and writes it to the screen or it
//can be redirected into another file if that is the intention.
int main()
{
char b[1];
int nread;
//reads each character of input to buffer (b)
while ((nread = read(0,b,1)>0)){
    if(nread != -1){
        //writes buffer to standard output if there are no errors with reading.
    write (1,b,nread);
    } else {
        //prints if something goes wrong with the reading process.
        printf("reading error");
    }
}
return 0;
}
