/*
LAB03 TASK05
Mark Schweitzer
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */


//this program shows how lseek can be used to navigate through a file by reading a file in reverse using lseek to go back each go throuhg.
//loop terminates once lseek hits zero.
int main()
{
    umask(0);
    char b[1];
int nread,floomp,foorev,f,n = 0;
floomp = open("foo.dat", O_RDONLY);
foorev = open("foorev.dat", O_RDWR | O_CREAT | O_EXCL, 0760);
if(floomp != -1 && foorev != -1){
    f=lseek(floomp,0,SEEK_END);
while (f >= 0){
    f=lseek(floomp,-2,SEEK_CUR);
    //offset is set to -2 since write increases offset by 1 so -1 would just balance it out, leading to an infinite loop.
    if ((nread = read(floomp,b,1)>0)){
    write (foorev,b,nread);
    } else {
        //prints if something goes wrong with the reading process.
        printf("File read error");
    }
}
} else if (nread == -1) {
    //prints if something goes wrong with the file opening process.
    printf("File open error or file already exists.");
}
close(floomp);
close(foorev);
exit(0);
}
