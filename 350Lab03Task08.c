/*
LAB03 TASK08
Mark Schweitzer
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h> /* defines options flags */
#include <sys/types.h> /* defines types used by sys/stat.h */
#include <sys/stat.h> /* defines S_IREAD & S_IWRITE */
//This program takes an input file and converts its contents into ASCII numbers before printing the contents out to another file.
//This is done by converting each character into an ASCII number before splitting each digit of the number into individual characters 
//before writing it to an output file. Does account for spaces and newlines.

//function that directly takes an integer and makes it into a character equivalent of itself. (ex: integer 0 = '0').
char returnchar(int i){
    if(i == 0){
        return '0';
    }
    if(i == 1){
        return '1';
    }
    if(i == 2){
        return '2';
    }
    if(i == 3){
        return '3';
    }
    if(i == 4){
        return '4';
    }
    if(i == 5){
        return '5';
    }
    if(i == 6){
        return '6';
    }
    if(i == 7){
        return '7';
    }
    if(i == 8){
        return '8';
    }
    if(i == 9){
        return '9';
    }
}


int main( int argc, char *argv[] ) 
{
    umask(0);
    //reserves buffer for the character and for the 3-digit ASCII number
    char temp[3];
    char b[1];
    int nread = 0;
int k = open(argv[1], O_RDONLY);
int v = open(argv[2], O_RDWR | O_CREAT | O_EXCL, 0666);
if(v != -1 && k != -1){
while ((nread = read(k,b,1)>0)){
    if(nread > 0){
if (*b != ' ' && *b != '\n'){
    int x = *b - '\0';
    //turns each digit of x into a single number v and turns each into the parts of the temporary buffer.
    for(int e = 2; e > -1; e--){
    int v = x%10;
    temp[e]=returnchar(v);
    x = x - v;
    x = x/10;
    }
    //writes the 3-digit temp buffer into the file.
    write(v,temp,3);
    } else {
        //writes character S to signify where there is a space.
        if(*b == ' '){
            char *f = ("S");
            write(v,f,1);
        }
        //writes character N to signify where there is a new line.
if(*b == '\n'){
            char *f = ("N");
            write(v,f,1);
        }
    }
    } else {
        //prints if something goes wrong with reading.
        printf("File reading error.");
    }
}
} else {
    //prints if something goes wrong with opening the file.
    printf("File open error or file already exists.");
}
close(k);
close(v);
exit (0);
}
