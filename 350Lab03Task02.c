/*
LAB03 TASK02
Mark Schweitzer

*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

//similar to previous problem, except the input is obtained through the open() system call and the output is written to another file.
int main()
{
    umask(0);
char b[1];
int nread;
int floomp,floomp2 = 0;
//opens foo.dat as a read only file since the program only looks at the file, but doesnt do anything else with it, and it creates a file called "clone1.dat" to put the new data into from foo.dat.
floomp = open("foo.dat", O_RDONLY); 
floomp2 = open("clone1.dat",O_CREAT | O_RDWR | O_EXCL, 0666); 
if(floomp != -1 && floomp2 != -1){

while ((nread = read(floomp,b,1)>0)){
    if(nread != -1){
    write (floomp2,b,nread);
    } else {
        //prints if something goes wrong with the file reading process.
        printf("reading error");
    }
}

} else {
    //prints if something goes wrong with the file opening process.
    printf("file read error or file already exists.");
}
close(floomp);
close(floomp2);
return 0;
}
