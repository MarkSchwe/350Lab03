#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

//similar to previous problem except instead of reading out the entire file, the output is restricted to 32 bytes.
int main()
{
    umask(0);
    //buffer of size 32
char buffer[32];
int nread, floomp, floomp2 = 0;
floomp = open("foo.dat", O_RDONLY); 
floomp2 = open("clone2.dat", O_RDWR | O_CREAT | O_EXCL, 0770);
if(floomp != -1 && floomp2 != -1){
    //nread's size is 32 for the size of the buffer.
    nread = read(floomp,buffer,32);
   if (nread != -1){
        write(floomp2,buffer,nread);
    } else {
        //prints if there is an issue with the read process.
        printf("read error");
    }
} else 
{
    //prints if something goes wrong with the file opening process.
    printf("File open error or creation error");
}
close(floomp);
close(floomp2);
exit(0);
}
