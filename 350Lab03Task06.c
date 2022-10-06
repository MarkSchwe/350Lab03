#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

//this program uses pread to write to a file an input file's contents in reverse.
int main()
{
    umask(0);
    char b[1];
int nread,floomp,foorev,f = 0;
floomp = open("foo.dat", O_RDONLY);
foorev = open("foorev.dat", O_RDWR | O_CREAT | O_EXCL, 0760);
if(floomp != -1 && foorev != -1){
int n = 0;
//used to set offset to the end of the input file akin to how lseek would be used.
while (nread = pread(floomp,b,1,n+1)>0){
    n=n+1;
}
//goes back through the file in reverse order and writes the contents to an output file.
while (nread = pread(floomp,b,1,n-1)>0){
    write (foorev,b,nread);
    n=n-1;
}
} else {
    //prints if something goes wrong with opening the file.
    printf("File open error or file already exists.");
}
close(floomp);
close(foorev);
exit(0);
}
