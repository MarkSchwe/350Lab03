#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */

//Serving as a demonstration of how lseek can be used, this program concatinates two files into another by taking the input from one and
//sending it to another file, but instead of immediately heading to the other file, both the input and output files are closed, in the
//process resetting its offset back to zero before opening the output file again along with a new input file. lseek is then used to 
//bring the user back to the place they were at in the output file before continuing writing text to it from the second input file.
int main()
{
    umask(0);
    char b[1];
int nread, nread2, floomp, floomp2, floomp12, foops = 0;
floomp = open("foo.dat", O_RDONLY); 
floomp12 = open("foo12.dat", O_RDWR | O_CREAT | O_EXCL, 0760);
if(floomp != -1 && floomp12 != -1){
    //reads all of foo.dat's contents and prints it to foo12.dat
while ((nread = read(floomp,b,1)>0)){
    if(nread != -1){
    write (floomp12,b,nread);
    } else {
        //prints if something goes wrong with the reading process.
        printf("reading error");
        break;
    }
}
} else {
    //prints if something goes wrong with the file opening process for foo.dat and/or foo12.dat
    printf("opening error or file already exists.");
}
//closes the input and output files and reopens the output file and opens the second input file.
close(floomp);
close(floomp12);
floomp12 = open("foo12.dat", O_RDWR | O_EXCL);
floomp2 = open("foo1.dat", O_RDONLY);
//to check if opening goes well.
if(floomp2 != -1 && floomp12 != -1){

//offset is reset here.
lseek(floomp12,0,SEEK_END);
//offset is restored to where it was before being closed here.
while ((nread = read(floomp2,b,1)>0)){
    if(nread != -1){
    write (floomp12,b,nread);
    } else {
        //prints if something goes wrong with the reading process.
        printf("reading error");
        break;
    }
}
} else {
    //prints if something goes wrong with the file process.
    printf("opening error ir file already exists (cannot recreate)");
}
close(floomp12);
close(floomp2);
exit(0);
}
